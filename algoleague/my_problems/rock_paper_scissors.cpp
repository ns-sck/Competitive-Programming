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

vi sz, val, dep, par;
vvi adj;
int t = 0;

void dfs(int u, int p = -1) {
    t += val[u];
    sz[u] = val[u];
    if (!adj[u].size()) dep[u] = 0;

    for (auto v : adj[u]) {
        if (v == p) continue;
        par[v] = u;
        dfs(v, u);
        sz[u] += sz[v];
        dep[u] = max(dep[u], dep[v] + 1);
    }
}

void solve() {
    int N, Q;
    cin >> N >> Q;

    sz.assign(N, 0);
    val.assign(N, 0);
    dep.assign(N, 0);
    adj.assign(N, {});
    par.assign(N, -1);

    for (int i = 1; i < N; ++i) {
       int p; cin >> p;
       adj[--p].pb(i);
    }

    for (int i = 0; i < N; ++i) {
        cin >> val[i];
    }

    int root = 0;

    if (adj[0].size() == 1) {
        root = adj[0][0];
        adj[0].clear();
        adj[root].pb(0);
    }

    dfs(root);

    map<int, bool> up;
    up[root] = 1;

    int c = 0, go = -1;
    for (auto v : adj[root]) {
        if (dep[v]) ++c, go = v;
        else up[v] = 1;
    }

    set<pi> s;

    for (int i = 0; i < N; ++i) {
        if (dep[i] == 1) {
            s.emplace(sz[i], i);
        }
    }

    put(max(sz[go], t - s.begin()->first));

    while (Q--) {
        int u, a;
        cin >> u >> a;
        --u;
        int add = a - val[u];
        val[u] = a;
        t += add;
        
        if (!up[u] && dep[u] <= 1) {
            if (!dep[u]) u = par[u];
            auto it = s.find({sz[u], u});
            s.erase(it);
            sz[u] += add;
            sz[go] += add;
            s.emplace(sz[u], u);
        } 

        put(max(sz[go], t - s.begin()->first));
    }
}

/*
15 5
1 2 2 4 4 6 6 8 5 12 14 2 13 14
5 3 10 2 4 7 8 4 10 6 1 5 9 12 8
6 27
11 100
11 0
6 7
11 1
*/

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}