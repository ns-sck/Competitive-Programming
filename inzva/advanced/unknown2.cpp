#include <bits/stdc++.h>


#pragma GCC optimize("O3")
#pragma GCC target("sse4")


#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define lsb(i) i&(-i)
#define sz(i) (int)i.size()
#define PI 3.14159265
#define bl '\n'
 

typedef long long ll;
using namespace std;
const ll INF = 1e18L;
constexpr ll mod = ll(1e9) + 7;


ll t=1, cases = 0, n, q, timee = 1;
vector<vector<int>> adj, lca;
vector<int> in, out, dep;


void dfs(int x, int p, int depth) {
    lca[x][0] = p;
    dep[x] = depth;
    in[x] = ++timee;

    for(int v : adj[x]) {
        if(v != p)
            dfs(v, x, depth + 1);
    }

    out[x] = ++timee;
}


bool is_ancestor(int v, int u) {
    return (in[v] <= in[u] and out[v] >= out[u]);
}


int find_lca(int v, int u) {
    if(is_ancestor(v, u))
        return v;
    if(is_ancestor(u, v))
        return u;

    for(int i = 19; i >= 0; i--) {
        if(!is_ancestor(lca[u][i], v)) {
            u = lca[u][i];
        }
    }

    return lca[u][0];
}


void solve(){
    cin >> n >> q;

    adj.resize(n + 1);
    dep.resize(n + 1);
    in.resize(n + 1);
    out.resize(n + 1);

    for(int i = 1; i < n; i++) {
        int x, y; cin >> x >> y;

        adj[x].pb(y);
        adj[y].pb(x);
    }

    lca.resize(n + 1, vector<int>(20, 1));

    dfs(1, 1, 0);

    for(int i = 1; i < 20; i++) {
        for(int j = 1; j <= n; j++) {
            if(lca[j][i - 1] != -1)
                lca[j][i] = lca[lca[j][i - 1]][i - 1];
        }
    }

    while(q--) {
        int u, v;

        cin >> u >> v;

        int lca_node = find_lca(v, u);
        int dist1 = dep[v] - dep[lca_node];
        int dist2 = dep[u] - dep[lca_node];

        cout << lca_node << ' ' << dist1 + dist2 << '\n';
    }
} 


int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    //cin>>t;
    for(; cases < t; cases++)solve();

    return 0;
}