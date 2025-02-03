#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<vector<int>>
#define mii map<int, int>
const int MOD = 1e9+7;
const int _max = 2e5+1;
int32_t main() {

    int n, m;
    cin >> n >> m;
    vector<vector<pii>> adj(_max, vector<pii>());
    while (m--) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({c, b});
    }
    vi dist(_max, 1e18);
    priority_queue<pii, vector<pii>, greater<>>  pq;
    pq.push({0, 1});
    dist[1] = 0;
    while (pq.size()) {
        auto p = pq.top();
        pq.pop();
        int node = p.second;
        int dis = p.first;
        if (dis > dist[node])
            continue;
        for (auto p : adj[node]) {
            int neigh = p.second;
            int cos = p.first;
            if (cos + dist[node] < dist[neigh]) {
                dist[neigh] = cos + dist[node];
                pq.push({dist[neigh], neigh});
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << dist[i] << ' ';
    }
    return 0;
}
