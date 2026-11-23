#include <iostream>
#include <vector>
#include <complex>
using namespace std;

vector<complex<long double>> fast_fourier_transform(const vector<complex<long double>> &A, bool inverse = false) {
    long long a_size = A.size();
    if (a_size == 1) return A;
    int dir = (inverse? -1 : 1);

    vector<complex<long double>> even, odd;
    for (int i = 0; i < a_size; i++) {
        if (i % 2 == 0) even.push_back(A[i]);
        else odd.push_back(A[i]);
    }

    vector<complex<long double>> E = fast_fourier_transform(even, inverse);
    vector<complex<long double>> O = fast_fourier_transform(odd, inverse);
    vector<complex<long double>> result;

    complex<long double> a[(a_size >> 1)]; 
    complex<long double> b = polar((long double) 1.0, (long double) dir * 2.0 * M_PI / a_size);
    a[0] = 1;
    for (int j = 1; j < (a_size >> 1); j++) {
        a[j] = a[j - 1] * b;
    }
    for (int j = 0; j < (a_size >> 1); j++) {
        result.push_back(E[j] + a[j] * O[j]);
    }

    for (int j = 0; j < (a_size >> 1); j++) {
        result.push_back(E[j] - a[j] * O[j]);
    }

    return result;
}

vector<complex<long double>> inverse_fast_fourier_transform(const vector<complex<long double>> &A) {
    vector<complex<long double>> result = fast_fourier_transform(A, true);
    for (int i = 0; i < result.size(); i++) result[i] /= A.size();
    return result;
}

constexpr long long power(long long base, long long exp) {
    long long res = 1;
    for (long long i = 0; i < exp; ++i) res *= base;
    return res;
}
class Large{
public:
    static const long long digits_size = 524288;
    static const long long base_digit = 5;
    static const long long base = power(10, base_digit);
    bool is_zero = true;
    bool is_negative = false;
    vector<long long> digits = vector<long long>(digits_size, 0);
    long long most_significant_digit = 0;
    Large() {}
    Large(int x) {
        *this = Large((long long)x);
    }
    Large(long x) {
        *this = Large((long long)x);
    }
    Large(long long x) {
        is_negative = (x < 0);
        is_zero = (x == 0);
        if (is_negative) {
            x = -x;
        }
        most_significant_digit = is_zero? 0 : ceil((long double)(log10(x) + 1) / base_digit);
        digits[0] = x % base;
        digits[1] = x / base;
    }
    Large(string x) {
        if (x == "0" || x == "-0") return;
        is_negative = (x[0] == '-');
        if (is_negative) x.erase(0, 1);
        long long buffer = 0;
        most_significant_digit = ceil((long long)x.length() / (long double) Large::base_digit);
        for (long long i = 0; i < x.length(); i++) {
            buffer *= 10;
            if (x[i] - '0' > 9 || x[i] - '0' < 0) throw invalid_argument("Invalid input of string: " + (is_negative? ("-" + x) : ("" + x) + "\nThere's a character " + x[i] + "in the string at index of " + char(i) + "."));
            buffer += x[i] - '0';
            if (i % Large::base_digit == ((long long)((Large::base_digit - 1 + x.length()) % Large::base_digit))) {
                digits[(x.length() - i) / Large::base_digit] = buffer;
                buffer = 0;
            }
        }
        is_zero = (most_significant_digit == 0);
    }
    Large operator=(const Large &B) {
        digits = B.digits;
        is_zero = B.is_zero;
        is_negative = B.is_negative;
        most_significant_digit = B.most_significant_digit;
        
        return *this;
    }
    bool operator==(const Large &B) const {
        if (most_significant_digit != B.most_significant_digit) return false;
        if (is_negative != B.is_negative) return false;
        if (is_zero != B.is_zero) return false;
        if (is_zero) return is_zero == B.is_zero;
        for (long long i = digits_size - 1; i >= 0; i--) if (digits[i] != B.digits[i]) return false;
        return true;
    }
    bool operator>(const Large &B) const {
        for (long long i = digits_size - 1; i >= 0; i--) {
            if (digits[i] > B.digits[i]) return true;
            else if (digits[i] < B.digits[i]) return false;
        }
        return false;
    }
    bool operator<(const Large &B) const {
        for (long long i = digits_size - 1; i >= 0; i--) {
            if (digits[i] < B.digits[i]) return true;
            else if (digits[i] > B.digits[i]) return false;
        }
        
        return false;
    }
    bool operator>=(const Large &B) const {return !(*this < B);}
    bool operator<=(const Large &B) const {return !(*this > B);}
    Large operator-() const {
        Large result = *this;
        if (is_zero) return result;
        result.is_negative = !result.is_negative;
        return result;
    }
    friend Large operator+(const Large &A, const Large &B);
    friend Large operator-(const Large &A, const Large &B);
    friend Large operator*(const Large &A, const Large &B);
    friend Large operator/(const Large &A, const Large &B);
    friend Large operator^(const Large &A, const long long &B);
    // friend Large operator>>(const Large &A, const Large &B);
    // friend Large operator<<(const Large &A, const Large &B);
};

istream &operator>>(istream &is, Large &A) {
    string a;
    is >> a;
    A = Large(a);
    return is;
}

ostream &operator<<(ostream &os, const Large &A) {
    if (A.is_zero || A.most_significant_digit == 0) {
        os << "0";
        return os;
    }
    if (A.is_negative) os << "-";

    os << A.digits[A.most_significant_digit - 1];
    for (long long i = A.most_significant_digit - 2; i >= 0; i--) {
        os.width(Large::base_digit);
        os.fill('0');
        os << A.digits[i];
    }
    os.width(0);
    os.fill(' ');
    return os;
}

void shift_left(vector<long long> &A, long long k) {
    if (k <= 0) return;
    A.erase(A.begin(), A.begin() + k);
    return;
}
void shift_right(vector<long long> &A, long long k) {
    if (k <= 0) return;
    if (k >= A.size()) {
        A.clear();
        A.push_back(0);
        return;
    }
    A.insert(A.begin(), k, 0);
    return;
}
Large operator+(const Large &A, const Large &B) {
    if (A.is_zero) return B;
    if (B.is_zero) return A;

    if (A.is_negative) {
        if (B.is_negative) return -(-A + -B);
        else return B - -A;
    } else if (B.is_negative) return A - -B;

    long long carry = 0;
    Large result;
    result.most_significant_digit = max(A.most_significant_digit, B.most_significant_digit);
    for (long long i = 0; i <= result.most_significant_digit ; i++) {
        result.digits[i] = A.digits[i] + B.digits[i] + carry;
        carry = (result.digits[i] >= Large::base);
        if (carry) result.digits[i] -= Large::base;
    }

    result.is_negative = A.is_negative;
    result.is_zero = false;


    if (result.digits[result.most_significant_digit] != 0) result.most_significant_digit++;
    
    return result;
}
Large operator-(const Large &A, const Large &B) {
    if (A.is_zero) return -B;
    if (B.is_zero) return A;
    if (A.is_negative) {
        if (B.is_negative) return -(-A - -B);
        else return -A + B;
    } else if (B.is_negative) return -(-A - -B);
    if (A < B) {
        return -(B - A);
    }
    if (A == B) return Large(0);
    long long carry = 0;
    Large result;
    result.most_significant_digit = max(A.most_significant_digit, B.most_significant_digit);
    result.is_negative = false;
    long long most_significant_digit = result.most_significant_digit;
    for (long long i = 0; i <= result.most_significant_digit; i++) {
        result.digits[i] = A.digits[i] - B.digits[i] - carry;
        
        if (result.digits[i] < 0) {
            result.digits[i] += Large::base;
            carry = 1;
        } else if (result.digits[i] > 0) most_significant_digit = i+1;
    }
    result.most_significant_digit = most_significant_digit;
    result.is_zero = result.most_significant_digit == 0;
    return result;
}
Large operator*(const Large &A, const Large &B) {
    //using FFT algorithm
    if (A.is_zero || B.is_zero) return Large(0);
    if (A.is_negative) {
        if (B.is_negative) return -A * -B;
        else return -(-A * B);
    } else if (B.is_negative) return -(A * -B);
    long long k = A.most_significant_digit + B.most_significant_digit - 1;
    long long n = 1;
    for (; n <= k; n *= 2);
    vector<complex<long double>> A_complex(n);
    vector<complex<long double>> B_complex(n);
    for (int i = 0; i < n; i++) {
        A_complex[i] = A.digits[i];
        B_complex[i] = B.digits[i];
    }
    A_complex = fast_fourier_transform(A_complex);
    B_complex = fast_fourier_transform(B_complex);
    for (int i = 0; i < n; i++) A_complex[i] *= B_complex[i];
    A_complex = inverse_fast_fourier_transform(A_complex);
    long long carry = 0;
    long long current = 0;
    Large result;
    result.most_significant_digit = k + 1;
    for (long long i = 0; i < result.most_significant_digit ; i++) {
        current = ((long long) std::llround(A_complex[i].real()) + carry);
        carry = current / Large::base;
        result.digits[i] = current % Large::base;
    }
    if (result.digits[result.most_significant_digit - 1] == 0) result.most_significant_digit--;
    result.is_negative = false;
    result.is_zero = false;
    return result;
}
Large operator/(const Large &A, const Large &B) {
    if (A.is_zero) return Large(0);
    if (B.is_zero) {
        throw runtime_error("divide by zero");
    }

    if (A == B) return Large(1);

    if (B == Large(1)) return A;

    if (A.is_negative) {
        if (B.is_negative) {
            return -A / -B;
        } else {
            return -(-A / B);
        }
    } else {
        if (B.is_negative) {
            return -(A / -B);
        }
    }

    if (A < B) {
        return Large(0);
    }

    // divident / divisor = quotient * divisor + remainder
    Large quotient = 0;
    Large remainder = A;
    Large divisor = B;
    long long carry = 0;
    bool leading_zero_decrease_flag = false;
    quotient.is_negative = false;
    quotient.is_zero = false;
    quotient.most_significant_digit = A.most_significant_digit - B.most_significant_digit + 1;

    divisor = divisor << quotient.most_significant_digit - 1;
    bool is_leading_zero = true;
    
    for (long long i = 0; i < quotient.most_significant_digit; i++) {
        long long divident = (remainder.digits[A.most_significant_digit - 1 - i] + carry) / divisor.digits[divisor.most_significant_digit - 1];
        for (long long j = 1; j <= divisor.most_significant_digit; j++) {
            if (
                    (
                        j == 1 && 
                        (remainder.digits[divisor.most_significant_digit - j] + carry) < divident * divisor.digits[divisor.most_significant_digit - j]
                    ) || (
                        j != 1 &&
                        remainder.digits[divisor.most_significant_digit - j] < divident * divisor.digits[divisor.most_significant_digit - j]
                    )
                ) {
                divident--;
                continue;
            }
        }

        if (divident == 0 && is_leading_zero) {
            leading_zero_decrease_flag = true;
        }
        is_leading_zero = false;

        if (divident == 0 && remainder.digits[A.most_significant_digit - 1 - i]) {
            carry = Large::base * remainder.digits[A.most_significant_digit - 1 - i];
            remainder = (remainder - divisor * divident);
        } else {
            remainder = (remainder - divisor * divident);
            carry = Large::base * remainder.digits[divisor.most_significant_digit - 1];
        }

        quotient.digits[quotient.most_significant_digit - i - 1] = divident;

        divisor = divisor >> 1;
    }

    if (leading_zero_decrease_flag) {
        quotient.most_significant_digit--;
    }

    return quotient;
}
Large operator>>(const Large &A, const Large &B) {
    if (A.is_zero) return Large(0);
    if (B.is_zero) return A;
    if (B.is_negative) return Large(0);
    if (B.digits[0] > Large::base) return Large(0);
    if (B.digits[0] > A.most_significant_digit) return Large(0);
    Large result = A;
    shift_left(result.digits, B.digits[0]);
    result.is_zero = false;
    result.most_significant_digit = A.most_significant_digit - B.digits[0];
    return result;
}
Large operator<<(const Large &A, const Large &B) {
    if (A.is_zero) return Large(0);
    if (B.is_zero) return A;
    if (B.is_negative) return Large(0);
    if (B.digits[0] > Large::base) return Large(0);
    Large result = A;
    shift_right(result.digits, B.digits[0]);
    result.is_zero = false;
    result.most_significant_digit = A.most_significant_digit + B.digits[0];
    return result;
}
Large operator^(const Large &A, const long long &B) {
    if (B == 0) return Large(1);
    if (A.is_zero) return Large(0);
    if (A == Large(1)) return Large(1);
    if (B == 1) return A;
    if (A.is_negative) return (B % 2 == 0)? -A ^ B : -(-A ^ B);
    if (B < 0) return 0;
    Large result = A;
    
    if (B % 2 == 0) {
        result = result ^ (B / 2);
        result = result * result;
    } else {
        result = result ^ ((B - 1) / 2);
        result = result * result;
        result = result * A;
    }
    return result;
}
int main() {
    Large a, c;
    char b;
    while (cin >> a >> b >> c) {
        if (a == 0 || b == 0) break;
        if (b == '+') a = a + c;
        if (b == '-') a = a - c;
        if (b == '*') a = a * c;
        if (b == '/') a = a / c;
        // if (b == '^') a = a ^ c;
        cout << a << endl;
    }
    return 0;
}