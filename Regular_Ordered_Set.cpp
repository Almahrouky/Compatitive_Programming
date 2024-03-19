#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
typedef long long ll; typedef long double ld;
#define int       long long
#define sz(v)     (long long)(v.size())
#define fr(n)     for(int i = 0; i < n; ++i)
#define frj(m)    for(int j = 0; j < m; ++j)
#define all(v)    v.begin(), v.end()
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// find_by_order(k): It returns to an iterator to the kth element
// order_of_key(k) : It returns to the number of items that are strictly smaller than k
int dx[] = {0, 1, 0, -1, -1, 1, 1, -1}; int dy[] = {1, 0, -1, 0, 1, 1, -1, -1}; char di[] = {'R', 'D', 'L', 'U'};
void Almahrouky() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
    freopen("error.txt", "w", stderr);
#endif
}
const int mod = 1e9 + 7, inf = 1e18, N = 2e5 + 1, M = 1e5 + 5;

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
