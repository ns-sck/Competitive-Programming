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
const ll MAX = 1e6+1;

int root = -1, mx1, mx2;
int dia;
vi adj[MAX];
int go[MAX], go2[MAX];
int par[MAX];
set<int> ans;

int dfs(int u, int p = -1) {
    par[u] = p;
    int m1 = 0, m2 = 0;
    for (auto v : adj[u]) {
        if (v == p) continue;
        int x = dfs(v, u);
        if (x > m1) {
            m2 = m1;
            m1 = x;
        } else if (x > m2) {
            m2 = x;
        }
    }
    if (root == -1 || m1 + m2 >= mx1 + mx2) {
        root = u;
        mx1 = m1;
        mx2 = m2;
    }
    go[u] = m1, go2[u] = m2;
    return m1 + 1;
}

void dfs2(int u, int p = par[root]) {
    ans.insert(u);
    int m1 = go[u], m2 = go2[u];
    for (auto v : adj[u]) {
        if (v == p) continue;
        if (m1 + m2 == dia && go[v] + 1 >= m2) {
            dfs2(v, u);
        } else if (go[v] + 1 == go[u]) {
            dfs2(v, u);
        }
    }
}

void solve() {
    int N; cin >> N;
    int nn = N;
    while (--nn) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1);
    dia = mx1 + mx2;
    dfs2(root);

    for (auto x : ans) cout << x << ' ';
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