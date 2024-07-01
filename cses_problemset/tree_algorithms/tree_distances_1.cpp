#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define ld long double
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

vi adj[MAX];
int up[MAX], dw[MAX];

void dfs(int u = 1, int p = -1) {
    for (auto v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        dw[u] = max(dw[u], dw[v]+1);
    }
}

void dfs2(int u = 1, int p = -1) {
    int m1 = 0, m2 = 0;
    for (auto v : adj[u]) {
        if (v == p) continue;
        if (dw[v] >= dw[m1]) {
            m2 = m1;
            m1 = v;     
        } else if (dw[v] > dw[m2]) m2 = v;
    }

    for (auto v : adj[u]) {
        if (v == p) continue;
        up[v] = max(up[v], up[u]+1);
        if (v == m1) {
            if (m2) up[v] = max(up[v], dw[m2]+2);
        } else if (m1 != 0) {
            up[v] = max(up[v], dw[m1]+2);
        }
        dfs2(v, u);
    }
}

void solve() {
    // https://github.com/Jonathan-Uy/CSES-Solutions/blob/main/Tree%20Algorithms/Tree%20Distances%20I.cpp
    int N; cin >> N;
    for (int i = 1; i < N; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs();
    dfs2();
    for (int i = 1; i <= N; ++i) cout << max(up[i], dw[i]) << ' ';
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
