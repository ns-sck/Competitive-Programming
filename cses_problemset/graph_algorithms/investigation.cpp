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

vpi adj[MAX];
vi par[MAX];
vi dis(MAX, INF);
int c[MAX];
bool vis[MAX];

void solve() {
    int N, M;
    cin >> N >> M;

    while (M--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
    }

    priority_queue<pi, vpi, greater<>> pq;
    pq.push({0, 1});

    while (pq.size()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (dis[u] <= d) continue;
        dis[u] = d;

        for (auto [v, w] : adj[u]) {
            if (d + w <= dis[v]) {
                if (d + w == dis[v]) {
                    par[v].clear();
                } else {
                    pq.push({d + w, v});
                }
                par[v].pb(u);
            } 
        }
    }

    int x = 0, y = INF, z = INF;

    priority_queue<pair<int, pi>, vector<pair<int, pi>>, greater<>> qp;
    qp.push({0, {0, 1}});
    c[1] = 1;
    while (qp.size()) {
        auto[d, pr] = qp.top();
        auto [a, u] = pr;
        qp.pop();
        if (vis[u]) continue;
        if (u == N) y = a;
        vis[u] = 1;
        ++x;

        for (auto [v, w] : adj[u]) {
            if (dis[v] == d + w) {
                c[v] = (c[v] + c[u]) % MOD;
                qp.push({d + w, {a + 1, v}});
            }
        }
    }

    memset(vis, 0, sizeof(vis));
    priority_queue<pair<int, pi>, vector<pair<int, pi>>, greater<>> qq;
    qq.push({0, {0, 1}});
    while (qq.size()) {
        auto[d, pr] = qq.top();
        auto [a, u] = pr;
        qq.pop();
        if (vis[u]) continue;
        if (u == N) z = a;
        vis[u] = 1;
        ++x;

        for (auto [v, w] : adj[u]) {
            if (dis[v] == d + w) {
                qq.push({d + w, {a - 1, v}});
            }
        }
    }

    put(dis[N], c[N], y, -z);

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
