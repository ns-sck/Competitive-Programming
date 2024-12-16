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
 
    vi p(N + 1);
 
    dis[1] = 0;
 
    for (int i = 0; i < 2 * N; ++i) {
        for (auto e : edg) {
            int w = e[0], u = e[1], v = e[2];
            int x = dis[v];
            if (dis[v] > dis[u] + w) {
                p[v] = u;
                dis[v] = dis[u] + w;
                if (i >= N - 1 && x > dis[v]) {
                    u = v;
                    for (int i = 0; i < N; ++i) u = p[u];
                    vi ans;
                    ans.pb(u);
                    int st = p[u];
                    while (st != u) {
                        ans.pb(st);
                        st = p[st];
                    }
                    ans.pb(u);
                    reverse(all(ans));
                    put("YES");
                    for (int& x : ans) cout << x << ' ';
                    exit(0);
                }
            }
        }
    }
    put("NO");
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