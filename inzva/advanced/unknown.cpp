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


ll t=1, cases = 0, n, q;
vector<vector<int>> adj;


void dfs(int x, int p, vector<vector<int>> &lca) {
    lca[x][0] = p;

    for(int v : adj[x]) {
        if(v != p)
            dfs(v, x, lca);
    }
}


void solve(){
    cin >> n >> q;

    adj.resize(n + 1);

    for(int i = 1; i < n; i++) {
        int x, y; cin >> x >> y;

        adj[x].pb(y);
        adj[y].pb(x);
    }

    vector<vector<int>> lca(n + 1, vector<int>(20, -1));

    dfs(1, -1, lca);

    for(int i = 1; i < 20; i++) {
        for(int j = 1; j <= n; j++) {
            if(lca[j][i - 1] != -1)
                lca[j][i] = lca[lca[j][i - 1]][i - 1];
        }
    }

    while(q--) {
        int node, k;

        cin >> node >> k;

        for(int i = 0; i < 20 and node != -1; i++) {
            if((1 << i) & k) {
                node = lca[node][i];
            }
        }

        cout << node << '\n';
    }
} 


int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    //cin>>t;
    for(; cases < t; cases++)solve();

    return 0;
}