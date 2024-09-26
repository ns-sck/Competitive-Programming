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

vvi edg;
vi dis(MAX, -INF);
vi adj[MAX], rev[MAX];
bool vis0[MAX], vis1[MAX];

void solve() {
    int N, M;
    cin >> N >> M;

    while (M--) {
        int u, v, w;
        cin >> u >> v >> w;

        edg.pb({w, u, v});
        rev[v].pb(u);
        adj[u].pb(v);
    }

    vi q;
    q.pb(N);

    int i = 0;
    while (i < q.size()) {
        int u = q[i];
        ++i;
        if (vis0[u]) continue;
        vis0[u] = 1;
        for (auto v : rev[u]) {
            q.pb(v);
        }
    }
    
    q.resize(0);

    q.pb(1);
    i = 0;
    while (i < q.size()) {
        int u = q[i];
        ++i;
        if (vis1[u]) continue;
        vis1[u] = 1;
        for (auto v : adj[u]) {
            q.pb(v);
        }
    }

    dis[1] = 0;

    for (int i = 0; i < 2 * N; ++i) {
        for (auto e : edg) {
            int w = e[0], u = e[1], v = e[2];
            int x = dis[v];
            dis[v] = max(dis[v], dis[u] + w);
            if (i >= N && x < dis[v] && vis0[v] && vis1[v]) {
                put(-1);
                return;
            }
        }
    }
    put(dis[N]);
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