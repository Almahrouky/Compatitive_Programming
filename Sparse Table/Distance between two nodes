#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7, inf = 1e9, N = 2e5 + 7, M = 1e5 + 7, LG = 20;
// anc[i][k] is the 2^kth ancestor of node i
int n;
int p[N];
vector<int> adj[N];
vector<int> child[N];
int depth[N];
int anc[N][LG];
void dfs(int u, int dep = 0, int par = 0){
    depth[u] = dep;
    p[u] = par;
    for(auto ch:adj[u])
        if(ch == par) continue;
        else dfs(ch, dep + 1, u);
}
void con(){
    for(int i = 1; i <= n; ++i)
        anc[i][0] = p[i];
 
    for(int L = 1; L < LG; ++L)
        for(int i = 1; i <= n; ++i)
            anc[i][L] = anc[anc[i][L - 1]][L - 1];
}
int binLift(int u, int up){
    for(int i = 0; i < 31; ++i)
        if(up&(1<<i))
            u = anc[u][i];
 
    return u;
}
int LCA(int a, int b){
    if(depth[a] < depth[b])
        swap(a, b);

    a = binLift(a, depth[a] - depth[b]);
    if(a == b)
        return a;
    for(int bit = LG - 1; ~bit; --bit){
        if(anc[a][bit] == anc[b][bit])
            continue;
        a = anc[a][bit];
        b = anc[b][bit];
    }
    return anc[a][0];
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    
    int q; cin>>n>>q;
    for(int i = 2; i <= n; ++i){
        int u, v; cin>>u>>v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    dfs(1);
    con();
    while(q--){
        int u, v; cin>>u>>v;
        int com = LCA(u, v);
        cout<<depth[u] - depth[com] + depth[v] - depth[com]<<'\n';
    }
    /*
    the root of 1 is 0 and any kth root of 0 is 0 (self loop)
    so we don't care about out of range
    */
    return 0;
}
