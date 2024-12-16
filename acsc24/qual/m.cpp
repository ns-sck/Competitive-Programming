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
    const ld EPS = 1e-9; 

    int par[MAX];
    int sz[MAX];

    int find(int u) {
        return u == par[u] ? u : par[u] = find(par[u]);
    }
    
    void uni(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return;
        if (sz[u] > sz[v]) swap(u, v);
        par[u] = v;
        sz[v] += sz[u];
    }
    ll t[MAX];
    void solve() {
        int N, M;
        cin >> N >> M;
        for (int i = 1; i <= N; ++i) {
            string s; cin >> s;
            if (s == "T") t[i] = 1;
            else t[i] = -1;
        }
        vector<ar<int, 4>> edg;
        while (M--) {
            int u, v, w;
            cin >> u >> v >> w;
            bool b = t[u] == t[v];
            edg.push_back({w, 1-b, u, v});
            par[u] = u, par[v] = v;
        }
        sort(all(edg));
        int ans = 0, ed = 0;
        for (auto& e : edg) {
            int w = e[0], u = e[2], v = e[3];
            if (find(u) != find(v)) {
                if (t[u] ^ t[v]) ans += 1;
                uni(u, v);
                ++ed;
            }
        }
        if (ed ^ (N-1)) cout << -1 << '\n';
        else cout << ans << '\n';
    }

    signed main () {

        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        
        int t = 1;
        // cin >> t;
        while (t--) solve();

        return 0;
    }
