#include <bits/stdc++.h>
using namespace std;
 
template<typename... T>
void put(T&&... args) { ((cout << args << " "), ...); cout << '\n';}
 
#define int long long
#define ll long long
#define pi pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpi vector<pi>
#define pb push_back
#define ar array
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
 
const ll MOD = 1e9+7;
const ll INF = 1e18;
const ll MAX = 2e5+1;
 
int N, M;
bool vis[MAX];
vi adj[MAX];
vi rev[MAX];
vi adj_cond[MAX];
vvi comps;
 
void dfs(int v, vi* a, vi& output) {
    vis[v] = true;
    for (auto u : a[v])
        if (!vis[u])
            dfs(u, a, output);
    output.push_back(v);
}
 
void scc() {
 
    vi order;
 
    for (int i = 1; i <= N; i++)
        if (!vis[i])
            dfs(i, adj, order);
 
    for (int v = 1; v <= N; v++)
        for (int u : adj[v])
            rev[u].push_back(v);
 
    memset(vis, 0, sizeof(vis));
    reverse(all(order));
 
    vi roots(N + 1);
 
    for (auto v : order)
        if (!vis[v]) {
            vi comp;
            dfs(v, rev, comp);
            sort(all(comp));
            comps.push_back(comp);
            int root = comp.front();
            for (auto u : comp)
                roots[u] = root;
        }
 
 
    for (int v = 1; v <= N; v++)
        for (auto u : adj[v])
            if (roots[v] != roots[u])
                adj_cond[roots[v]].push_back(roots[u]);
}
 
void solve() {
    cin >> N >> M;
    
    while (M--) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
    }
 
    scc();
 
    memset(vis, 0, sizeof(vis));
    int ans[N+1];
 
    int c = 1;
    for (int i = 0; i < comps.size(); ++i) {
        for (int& u : comps[i]) {
            ans[u] = c;
        }
        ++c;
    }
 
    put(comps.size());
    
    for (int i = 1; i <= N; ++i) {
        cout << ans[i] << ' ';
    }
}
 
signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int t = 1;
    // cin >> t;
    while (t--) solve();
 
    return 0;
}