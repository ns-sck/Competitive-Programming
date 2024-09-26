#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<vector<int>>
#define mii map<int, int>
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
const int MOD = 1e9+7;
const int MAX = 2e5+1;
int par[MAX];
int sz[MAX];

int find(int u) {
    return u == par[u] ? u : par[u] = find(par[u]);
}
 
void uni(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) return;
    if (sz[u] > sz[v]) swap(u, v);
    par[u] = v;
    sz[v] += sz[u];
}

int32_t main() {

    ios;
    int n, m;
    cin >> n >> m;
    vii adj(MAX, vi());
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i) {
        par[i] = i;
        sz[i] = 1;
    }
    for (int i = 1; i < n; ++i) {
        for (auto neigh : adj[i]) {
            if (par[neigh] ^ par[i])
                uni(i, neigh);
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << par[i] << ' ';
    }
    return 0;
}
