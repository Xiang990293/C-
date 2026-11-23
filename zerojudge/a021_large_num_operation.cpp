#include <iostream>
#include <vector>
#include <complex>
using namespace std;

#define ll long long
#define ld long double
#define v vector
#define comp complex
#define pb push_back
#define len length
#define con const

v<comp<ld>> fft(con v<comp<ld>> &A, bool inv = false) {
ll as = A.size();
if (as == 1) return A;
int dir = (inv? -1 : 1);
v<comp<ld>> e, o;
for (int i = 0; i < as; i++) {
if (i % 2 == 0) e.pb(A[i]);
else o.pb(A[i]);
}
v<comp<ld>> E = fft(e, inv);
v<comp<ld>> O = fft(o, inv);
v<comp<ld>> re;
comp<ld> a[(as >> 1)]; 
comp<ld> b = polar((ld) 1.0, (ld) dir * 2.0 * M_PI / as);
a[0] = 1;
for (int j = 1; j < (as >> 1); j++) a[j] = a[j - 1] * b;
for (int j = 0; j < (as >> 1); j++) re.pb(E[j] + a[j] * O[j]);
for (int j = 0; j < (as >> 1); j++) re.pb(E[j] - a[j] * O[j]);
return re;
}
v<comp<ld>> inverse_fft(con v<comp<ld>> &A) {
v<comp<ld>> re = fft(A, true);
for (int i = 0; i < re.size(); i++) re[i] /= A.size();
return re;
}
constexpr ll power(ll base, ll exp) {
ll res = 1;
for (ll i = 0; i < exp; ++i) res *= base;
return res;
}
class Large{
public:
static con ll d_size = 524288;
static con ll bd = 4;
static con ll base = power(10, bd);
bool is0 = true;
bool is_neg = false;
v<ll> digits = v<ll>(d_size, 0);
ll msd = 0;
Large() {}
Large(int x) {
*this = Large((ll)x);
}
Large(long x) {
*this = Large((ll)x);
}
Large(ll x) {
is_neg = (x < 0);
is0 = (x == 0);
if (is_neg) {
x = -x;
}
msd = is0? 0 : ceil((ld)(log10(x) + 1) / bd);
digits[0] = x % base;
digits[1] = x / base;
}
Large(string x) {
if (x == "0" || x == "-0") return;
is_neg = (x[0] == '-');
if (is_neg) x.erase(0, 1);
ll buffer = 0;
msd = ceil((ll)x.len() / (ld) Large::bd);
for (ll i = 0; i < x.len(); i++) {
buffer *= 10;
if (x[i] - '0' > 9 || x[i] - '0' < 0) throw invalid_argument("Invalid input of string: " + (is_neg? ("-" + x) : ("" + x) + "\nThere's a character " + x[i] + "in the string at index of " + char(i) + "."));
buffer += x[i] - '0';
if (i % Large::bd == ((ll)((Large::bd - 1 + x.len()) % Large::bd))) {
digits[(x.len() - i) / Large::bd] = buffer;
buffer = 0;
}
}
is0 = (msd == 0);
}
Large operator=(con Large &B) {
digits = B.digits;
is0 = B.is0;
is_neg = B.is_neg;
msd = B.msd;

return *this;
}
bool operator==(con Large &B) con {
if (msd != B.msd) return false;
if (is_neg != B.is_neg) return false;
if (is0 != B.is0) return false;
if (is0) return is0 == B.is0;
for (ll i = d_size - 1; i >= 0; i--) if (digits[i] != B.digits[i]) return false;
return true;
}
bool operator>(con Large &B) con {
for (ll i = d_size - 1; i >= 0; i--) {
if (digits[i] > B.digits[i]) return true;
else if (digits[i] < B.digits[i]) return false;
}
return false;
}
bool operator<(con Large &B) con {
for (ll i = d_size - 1; i >= 0; i--) {
if (digits[i] < B.digits[i]) return true;
else if (digits[i] > B.digits[i]) return false;
}

return false;
}
Large operator-() con {
Large re = *this;
if (is0) return re;
re.is_neg = !re.is_neg;
return re;
}
friend Large operator+(con Large &A, con Large &B);
friend Large operator-(con Large &A, con Large &B);
friend Large operator*(con Large &A, con Large &B);
friend Large operator/(con Large &A, con Large &B);
friend Large operator^(con Large &A, con ll &B);
friend Large operator>>(con Large &A, con Large &B);
friend Large operator<<(con Large &A, con Large &B);
};

istream &operator>>(istream &is, Large &A) {
string a;
is >> a;
A = Large(a);
return is;
}

ostream &operator<<(ostream &os, con Large &A) {
if (A.is0 || A.msd == 0) {
os << "0";
return os;
}
if (A.is_neg) os << "-";

os << A.digits[A.msd - 1];
for (ll i = A.msd - 2; i >= 0; i--) {
os.width(Large::bd);
os.fill('0');
os << A.digits[i];
}
os.width(0);
os.fill(' ');
return os;
}

void shift_left(v<ll> &A, ll k) {
if (k <= 0) return;
A.erase(A.begin(), A.begin() + k);
return;
}
void shift_right(v<ll> &A, ll k) {
if (k <= 0) return;
if (k >= A.size()) {
A.clear();
A.pb(0);
return;
}
A.insert(A.begin(), k, 0);
return;
}
Large operator+(con Large &A, con Large &B) {
if (A.is0) return B;
if (B.is0) return A;

if (A.is_neg) {
if (B.is_neg) return -(-A + -B);
else return B - -A;
} else if (B.is_neg) return A - -B;

ll carry = 0;
Large re;
re.msd = max(A.msd, B.msd);
for (ll i = 0; i <= re.msd ; i++) {
re.digits[i] = A.digits[i] + B.digits[i] + carry;
carry = (re.digits[i] >= Large::base);
if (carry) re.digits[i] -= Large::base;
}
re.is_neg = false;
re.is0 = false;
if (re.digits[re.msd] != 0) re.msd++;

return re;
}
Large operator-(con Large &A, con Large &B) {
if (A.is0) return -B;
if (B.is0) return A;
if (A.is_neg) {
if (B.is_neg) return -(-A - -B);
else return -A + B;
} else if (B.is_neg) return -(-A - -B);
if (A < B) {
return -(B - A);
}
if (A == B) return Large(0);
ll carry = 0;
Large re;
re.msd = max(A.msd, B.msd);
re.is_neg = false;
ll msd = re.msd;
for (ll i = 0; i <= re.msd; i++) {
re.digits[i] = A.digits[i] - B.digits[i] - carry;

if (re.digits[i] < 0) {
re.digits[i] += Large::base;
carry = 1;
} else if (re.digits[i] > 0) msd = i+1;
}
re.msd = msd;
re.is0 = re.msd == 0;
return re;
}
Large operator*(con Large &A, con Large &B) {
//using FFT algorithm
if (A.is0 || B.is0) return Large(0);
if (A.is_neg) {
if (B.is_neg) return -A * -B;
else return -(-A * B);
} else if (B.is_neg) return -(A * -B);
ll k = A.msd + B.msd - 1;
ll n = 1;
for (; n <= k; n *= 2);
v<comp<ld>> A_comp(n);
v<comp<ld>> B_comp(n);
for (int i = 0; i < n; i++) {
A_comp[i] = A.digits[i];
B_comp[i] = B.digits[i];
}
A_comp = fft(A_comp);
B_comp = fft(B_comp);
for (int i = 0; i < n; i++) A_comp[i] *= B_comp[i];
A_comp = inverse_fft(A_comp);
ll carry = 0;
ll current = 0;
Large re;
re.msd = k + 1;
for (ll i = 0; i < re.msd ; i++) {
current = ((ll) std::llround(A_comp[i].real()) + carry);
carry = current / Large::base;
re.digits[i] = current % Large::base;
}
if (re.digits[re.msd - 1] == 0) re.msd--;
re.is_neg = false;
re.is0 = false;
return re;
}
Large operator/(con Large &A, con Large &B) {
if (A.is0) return Large(0);
if (B.is0) {
throw runtime_error("divide by zero");
}

if (A == B) return Large(1);

if (B == Large(1)) return A;

if (A.is_neg) {
if (B.is_neg) {
return -A / -B;
} else {
return -(-A / B);
}
} else {
if (B.is_neg) {
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
ll carry = 0;
bool leading_zero_decrease_flag = false;
quotient.is_neg = false;
quotient.is0 = false;
quotient.msd = A.msd - B.msd + 1;

divisor = divisor << quotient.msd - 1;
bool is_leading_zero = true;

for (ll i = 0; i < quotient.msd; i++) {
ll divident = (remainder.digits[A.msd - 1 - i] + carry) / divisor.digits[divisor.msd - 1];
for (ll j = 1; j <= divisor.msd; j++) {
if (
(
j == 1 && 
(remainder.digits[divisor.msd - j] + carry) < divident * divisor.digits[divisor.msd - j]
) || (
j != 1 &&
remainder.digits[divisor.msd - j] < divident * divisor.digits[divisor.msd - j]
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

if (divident == 0 && remainder.digits[A.msd - 1 - i]) {
carry = Large::base * remainder.digits[A.msd - 1 - i];
remainder = (remainder - divisor * divident);
} else {
remainder = (remainder - divisor * divident);
carry = Large::base * remainder.digits[divisor.msd - 1];
}

quotient.digits[quotient.msd - i - 1] = divident;

divisor = divisor >> 1;
}

if (leading_zero_decrease_flag) {
quotient.msd--;
}

return quotient;
}
Large operator>>(con Large &A, con Large &B) {
if (A.is0) return Large(0);
if (B.is0) return A;
if (B.is_neg) return Large(0);
if (B.digits[0] > Large::base) return Large(0);
if (B.digits[0] > A.msd) return Large(0);
Large re = A;
shift_left(re.digits, B.digits[0]);
re.is0 = false;
re.msd = A.msd - B.digits[0];
return re;
}
Large operator<<(con Large &A, con Large &B) {
if (A.is0) return Large(0);
if (B.is0) return A;
if (B.is_neg) return Large(0);
if (B.digits[0] > Large::base) return Large(0);
Large re = A;
shift_right(re.digits, B.digits[0]);
re.is0 = false;
re.msd = A.msd + B.digits[0];
return re;
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
cout << a << endl;
}
return 0;
}