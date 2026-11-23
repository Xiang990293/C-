#include <iostream>
#include <vector>
#include <complex>
using namespace std;

vector<complex<long double>> fast_fourier_transform(const vector<complex<long double>> &A, bool inverse = false) {
    if (A.size() == 1) return A;
    int dir = (inverse? -1 : 1);

    vector<complex<long double>> even, odd;
    for (int i = 0; i < A.size(); i++) {
        if (i % 2 == 0) even.push_back(A[i]);
        else odd.push_back(A[i]);
    }

    vector<complex<long double>> E = fast_fourier_transform(even, inverse);
    vector<complex<long double>> O = fast_fourier_transform(odd, inverse);
    vector<complex<long double>> result;

    complex<long double> a[E.size()]; 
    complex<long double> b = polar((long double) 1.0, (long double) dir * 2.0 * M_PI / A.size());
    a[0] = 1;
    for (int j = 1; j < E.size(); j++) {
        a[j] = a[j - 1] * b;
    }
    for (int j = 0; j < E.size(); j++) {
        result.push_back(E[j] + a[j] * O[j]);
    }

    for (int j = 0; j < E.size(); j++) {
        result.push_back(E[j] - a[j] * O[j]);
    }

    return result;
}

vector<complex<long double>> inverse_fast_fourier_transform(const vector<complex<long double>> &A) {
    vector<complex<long double>> result = fast_fourier_transform(A, true);

    for (int i = 0; i < result.size(); i++) {
        result[i] /= A.size();
    }

    return result;
}

constexpr long long power(long long base, long long exp) {
    long long res = 1;
    for (long long i = 0; i < exp; ++i) {
        res *= base;
    }
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
        if (is_negative) {
            x.erase(0, 1);
        }

        long long buffer = 0;
        most_significant_digit = ceil((long long)x.length() / (long double) Large::base_digit);
        for (long long i = 0; i < x.length(); i++) {
            buffer *= 10;
            if (x[i] - '0' > 9 || x[i] - '0' < 0) {
                throw invalid_argument("Invalid input of string: " + (is_negative? ("-" + x) : ("" + x) + "\nThere's a character " + x[i] + "in the string at index of " + char(i) + "."));
            }

            buffer += x[i] - '0';

            if (i % Large::base_digit == ((long long)((Large::base_digit - 1 + x.length()) % Large::base_digit))) {
                digits[(x.length() - i) / Large::base_digit] = buffer;
                buffer = 0;
            }
        }

        is_zero = (most_significant_digit == 0);
    }
    bool operator==(const Large &B) const {
        if (most_significant_digit != B.most_significant_digit) return false;
        if (is_negative != B.is_negative) return false;
        if (is_zero != B.is_zero) return false;
        if (is_zero) return is_zero == B.is_zero;

        for (long long i = digits_size - 1; i >= 0; i--) {
            if (digits[i] != B.digits[i]) {
                return false;
            }
        }
        
        return true;
    }

    Large operator-() const {
        Large result = *this;
        if (is_zero) return result;

        result.is_negative = !result.is_negative;
        
        return result;
    }
    friend Large operator*(const Large &A, const Large &B);
    friend Large operator^(const Large &A, const long long &B);
};

const Large zero = Large(0);
const Large one = Large(1);

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

    bool is_leading_zero = true;
    bool is_leading_digit = false;
    for (long long i = A.most_significant_digit - 1; i >= 0; i--) {
        if (is_leading_zero) {
            if (A.digits[i] == 0) continue;
            is_leading_zero = false;
            is_leading_digit = true;
        }
        
        if (is_leading_digit) {
            os << A.digits[i];
            os.width(Large::base_digit);
            os.fill('0');
            is_leading_digit = false;
        } else if (A.digits[i] == 0) {
            os.width(Large::base_digit);
            os << A.digits[i];
        } else {
            os.width(Large::base_digit);
            os << A.digits[i];
        }
    }
    os.width(0);
    os.fill(' ');
    
    return os;
}

Large operator*(const Large &A, const Large &B) {
    //using FFT algorithm

    if (A.is_zero || B.is_zero) return zero;

    if (A.is_negative) {
        if (B.is_negative) {
            return -A * -B;
        } else {
            return -(-A * B);
        }
    } else {
        if (B.is_negative) {
            return -(A * -B);
        }
    }

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
    for (int i = 0; i < n; i++) {
        A_complex[i] *= B_complex[i];
    }
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

    result.is_negative = false;
    result.is_zero = false;
    return result;
}

Large operator^(const Large &A, const long long &B) {
    if (B == 0) return one;
    if (A.is_zero) return zero;
    if (A == one) return one;
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
    long long b;
    while (cin >> a >> b) {
        if (a == 0 || b == 0) break;
        c = a ^ b;
        cout << c << endl;
    }

    return 0;
}