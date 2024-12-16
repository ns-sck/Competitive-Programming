#include <bits/stdc++.h>
using namespace std;

#define int long long

constexpr int MOD = 1e9+7;
constexpr int MAX = 2e5+1;

vector<vector<int>> adj;
vector<int> cnt;
int N, M;

int dfs(int u) {
    if (u == N) return 1;
    if (~cnt[u]) return cnt[u];
    int ans = 0;
    for (auto v : adj[u]) {
        int x = dfs(v);
        ans = (ans + x) % MOD;
    }
    return cnt[u] = ans;
}

void solve() {
    cin >> N >> M;
    adj.assign(N + 1, {});
    cnt.assign(N + 1, -1);
    while (M--) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
    }    
    cout << dfs(1) << '\n';
}

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}