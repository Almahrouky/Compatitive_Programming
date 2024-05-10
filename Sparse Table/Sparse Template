#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7, inf = 1e9, N = 1e5 + 7, M = 1e5 + 7, LG = 20;
int n;
int m[N][LG];
int a[N];
void con(){
    for(int i = 0; i < n; ++i)
        m[i][0] = a[i];
    for(int L = 1; L < LG; ++L)
        for(int i = 0; i + (1<<L) - 1 < n; ++i)
            m[i][L] = min(m[i][L - 1], m[i + (1<<(L - 1))][L - 1]);
}
int query(int l, int r){
    int len = r - l + 1;
    int j = 31 - __builtin_clz(len);

    return min(m[l][j], m[r - (1<<j) + 1][j]);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin>>n;
    for(int i = 0; i < n; ++i) cin>>a[i];
    con();

    int q; cin>>q;
    while(q--){
        int l, r; cin>>l>>r;
        cout<<query(l, r);
    }
    return 0;
}
