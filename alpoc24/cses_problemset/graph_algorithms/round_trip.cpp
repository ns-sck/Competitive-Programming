#include <bits/stdc++.h>
using namespace std;

template<typename... T>
void dbg(T&&... args) { ((cout << args << " "), ...); cout << '\n';}

#define int long long

constexpr int MOD = 1e9+7;
constexpr int MAX = 2e5+1;

vector<bool> vis;
vector<bool> act;
vector<int> par;
vector<vector<int>> adj;
int node = -1;

void dfs(int u, int p) {
	act[u] = 1;
	vis[u] = 1;
	for (auto v : adj[u]) {
		if (v == p) continue;
		if (act[v]) {
			par[v] = u;
			node = v;
			vector<int> path;
			int u = par[node];
			path.emplace_back(node);
			while (u != node) {
				path.emplace_back(u);
				u = par[u];
			}
			path.emplace_back(u);
			cout << path.size() << '\n';
			for (int& x : path) cout << x << ' ';
			cout << '\n';
			exit(0);
		}
		if (!vis[v]) {
			par[v] = u;
			dfs(v, u);
		}
	}
	act[u] = 0;
}
signed main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt = 1;
	// cin >> tt;
	while (tt--) {
		int N, M;
		cin >> N >> M;
		vis.assign(N + 1, 0);
		act.assign(N + 1, 0);
		par.assign(N + 1, 0);
		adj.assign(N + 1, {});
		node = -1;
		while (M--) {
			int u, v;
			cin >> u >> v;
			adj[u].emplace_back(v);
			adj[v].emplace_back(u);
		}
		for (int i = 1; i <= N; ++i) {
			if (vis[i]) continue;
			dfs(i, -1);
		}
		cout << "IMPOSSIBLE\n";
	}

	return 0;
}