#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
#define fr(n) for(int i = 0; i < n; ++i)
#define frj(m) for(int j = 0; j < m; ++j)
#define all(v) v.begin(), v.end()
int dx[] = {0, -1, 0, 1, -1, 1, 1, -1};
int dy[] = {1, 0, -1, 0, 1, 1, -1, -1};
char di[] = {'R', 'U', 'L', 'D'};
void Almahrouky() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
    freopen("error.txt", "w", stderr);
#endif
}
const int mod = 1e9 + 7;
const int inf = 1e18;
const int N = 2e5 + 5;
bool power_of_2(int n) {return __builtin_popcountll(n)==1;}
int add(int a, int b) {return ((a % mod) + (b % mod)) % mod;}
int mul(int a, int b) {return ((a % mod) * (b % mod)) % mod;}
int sub(int a, int b) {return ((a % mod) - (b % mod) + mod) % mod;}
int GCD(int a, int b) {return b == 0 ? a : GCD(b, a % b);}
int LCM(int a, int b) {return a / GCD(a, b) * b;}
int fast_power_recursive(int b, int p) {
    if (!p)
        return 1;
    int r = fast_power_recursive(b, p / 2);
    r *= r;
    if (p & 1)
        r *= b;
    return r;
}
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
void sol() {

}
int32_t main() { Almahrouky();
    int t = 1; cin >> t;
    while (t--) {
        sol();
        cout << '\n';
    }

    return 0;
}
