#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vii vector<vector<int>>
#define vi vector<int>
#define pii pair<int, int>

const int MOD = 1e9+7;
const int INF = 1e18;
const int _max = 2e5+1;

int32_t main () {

	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

    int n, m;
    cin >> n >> m;
    vi d(n+1, INF);
    vector<vector<pii>> adj(n+1, vector<pii>());
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
    }
    d[0] = 0;
    deque<int> q;
    q.push_front(0);
    while (!q.empty()) {
        int v = q.front();
        q.pop_front();
        for (auto edge : adj[v]) {
            int u = edge.first;
            int w = edge.second;
            if (d[v] + w < d[u]) {
                d[u] = d[v] + w;
                if (w == 1)
                    q.push_back(u);
                else
                    q.push_front(u);
            }
        }
    }
	return 0;
}
