// O(log)
#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7, inf = 1e16, N = 2e5 + 7, M = 1e5 + 7, LG = 20; // LG = 20 if N up to 1e6
// anc[i][k] is the 2^kth ancestor of node i
int n;
int p[N];
int anc[N][LG];
void con(){
    for(int i = 1; i <= n; ++i)
        anc[i][0] = p[i];

    for(int L = 1; L < LG; ++L)
        for(int i = 1; i <= n; ++i)
            anc[i][L] = anc[anc[i][L - 1]][L - 1];
}
int binLeft(int u, int up){
    for(int i = 0; i < 31; ++i)
        if(up&(1<<i))
            u = anc[u][i];

    return u;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int q; cin>>n>>q;
    for(int i = 2; i <= n; ++i)
        cin>>p[i];
    
    con();
    while(q--){
        int u, up; cin>>u>>up;
        int ans = binLeft(u, up);
        cout<<(ans == 0? -1:ans)<<'\n';
    }
    /*
    the root of 1 is 0 and any kth root of 0 is 0 (self loop)
    so we don't care about out of range
    */
    return 0;
}
