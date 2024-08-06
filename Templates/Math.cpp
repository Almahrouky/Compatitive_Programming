const int mod = 1e9 + 7;
bool power_of_2(int n) {return __builtin_popcountll(n)==1;}
int add(int a, int b) {return ((a % mod) + (b % mod)) % mod;}
int mul(int a, int b) {return ((a % mod) * (b % mod)) % mod;}
int sub(int a, int b) {return ((a % mod) - (b % mod) + mod) % mod;}
int GCD(int a, int b) {return b == 0 ? a : GCD(b, a % b);}
int LCM(int a, int b) {return a / GCD(a, b) * b;}
int fast_power_iterative(int a, int b) {
    int ret = 1;
    while (b > 0) {
        if (b & 1)
            ret *= a;
        a *= a;
        b /= 2;
    }
    return ret;
}