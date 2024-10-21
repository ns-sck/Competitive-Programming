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

vi adj[MAX];
bool win[MAX];

void dfs(int u, int p) {
    bool a = 0;
    for (auto v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        a |= win[v];
    }

    if (!a) win[u] = 1;
}

void solve() {
    int N, T;
    cin >> N >> T;

    int nn = N;
    while (--nn) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int x; cin >> x;

    dfs(x, -1);

    if (!win[x]) put("Ron");
    else put("Hermione");
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