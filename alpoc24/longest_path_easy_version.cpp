#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<int, int>
#define vi vector<int>
#define vii vector<vector<int>>
#define vpi vector<pi>
#define pb push_back
#define ar array
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

const ll MOD = 1e9+7;
const ll INF = 1e18;
const ll MAX = 3e5+1;
const long double EPS = 1e-9; 
vector<ar<int, 3>> adj[MAX];
vpi adj2[MAX];
vector<ll> d(MAX, INF), d2(MAX, INF);
vii p(MAX);
bool vis[MAX];
vi tin, low;
int n, m, timer;
void dfs(int v, int p = -1) {
    vis[v] = true;
    tin[v] = low[v] = timer++;
    for (auto& x : adj2[v]) {
        int to = x.first;
        int y = x.second;
        if (to == p) continue;
        if (vis[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v] && y) {
                cout << d[n-1]+1;
                exit(0);
            }
        }
    }
}

void solve() {

    cin >> n >> m;
    tin.assign(n, -1);
    low.assign(n, -1);
    while (m--) {
        int u, v, w1, a;
        cin >> u >> v >> w1 >> a;
        if (u ^ v) {
            adj[u].pb({v,w1,a});
            adj[v].pb({u,w1,a});
        }
    }
    priority_queue<ar<int, 2>, vector<ar<int, 2>>, greater<>> pq;
    pq.push({0,0});
    while (pq.size()) {
        auto [c, u] = pq.top();
        pq.pop();
        if (d[u] < c) continue;
        d[u] = c;
        for (auto a : adj[u]) {
            int v = a[0], w = a[1];
            if (c+a[1] < d[v]) {
                pq.push({c+a[1], v});
                d[v] = c+a[1];
            }
        }
    }
    pq.push({0,n-1});
    while (pq.size()) {
        auto [c, u] = pq.top();
        pq.pop();
        if (d2[u] < c) continue;
        d2[u] = c;
        for (auto a : adj[u]) {
            int v = a[0], w = a[1];
            if (c+a[1] < d2[v]) {
                pq.push({c+a[1], v});
                d2[v] = c+a[1];
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (auto a : adj[i]) {
            int w = a[1], v = a[0];
            if (d[i] + d2[v] + w == d[n-1] || d2[i] + d[v] + w == d[n-1])
                adj2[i].pb({v, a[2]});
        }
    }
    for (int i = 0; i < n; ++i) {
        if (!vis[i])
            dfs(i);
    }
    cout << d[n-1];
}   

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
