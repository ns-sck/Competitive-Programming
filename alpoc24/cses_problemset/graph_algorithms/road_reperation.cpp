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

int par[MAX];
int sz[MAX];
int ans = 0;
int w = 0, x = 1;

int fnd(int u) {
    return u == par[u] ? u : par[u] = fnd(par[u]);
}
 
void uni(int u, int v) {
    u = fnd(u), v = fnd(v);
    if (u == v) return;
    ans += w;
    ++x;
    if (sz[u] > sz[v]) swap(u, v);
    par[u] = v;
    sz[v] += sz[u];
}


void solve() {
    int N, M;
    cin >> N >> M;

    vvi edg;
    while(M--) {
        int u, v, w;
        cin >> u >> v >> w;
        edg.pb({w, u, v});
    }

    for (int i = 1; i <= N; ++i) {
        par[i] = i;
        sz[i] = 1;
    }

    sort(all(edg));

    for (auto ve : edg) {
        w = ve[0];
        int u = ve[1], v = ve[2];
        uni(u, v);
    }
    if (x == N) cout << ans << '\n';
    else cout << "IMPOSSIBLE";

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