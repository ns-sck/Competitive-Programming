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


// BISMILLAHIRRAHMANIRRAHIM

void solve() {
    int N, M, K;
    cin >> N >> M >> K;

    vvi adj(N);
    vi dis(N, INF);
    vector<bool> vis(N);

    while (M--) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    vi q;
    int i = 0;
    while (K--) {
        int u; cin >> u;
        --u;
        q.emplace_back(u);
        dis[u] = 0;
    }

    while (i < q.size()) {
        int u = q[i++];
        
        for (auto v : adj[u]) {
            if (dis[v] <= dis[u] + 1) continue;
            dis[v] = dis[u] + 1;
            q.emplace_back(v);
        }
    }

    vpi qq = {{0, (dis[0] - 1) >> 1}};
    i = 0;

    vi dis2(N, INF);
    dis2[0] = 0;

    while (i < qq.size()) {
        auto [u, d] = qq[i++];
        d = min(d, (dis[u] - 1) >> 1);
        vis[u] = 1;
        if (d <= 0) continue;

        for (auto v : adj[u]) {
            if (dis2[v] <= dis2[u] + 1) continue;
            dis2[v] = dis2[u] + 1;
            qq.pb({v, d - 1});
        }
    }
    
    vis[0] = 1;

    for (int i = 0; i < N; ++i) {
        cout << vis[i] << ' ';
    }

    cout << '\n';
}

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}