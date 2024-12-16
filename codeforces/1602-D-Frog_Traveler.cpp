#include <bits/stdc++.h>
using namespace std;

template<typename... T>
void dbg(T&&... args) { ((cout << args << " "), ...); cout << '\n';}

#define int long long

constexpr int MOD = 1e9+7;
constexpr int MAX = 2e5+1;

void solve() {
    int N; cin >> N;
    vector<int> a(N + 1), b(N + 1);
    for (int i = 1; i <= N; ++i) cin >> a[i];
    for (int i = 1; i <= N; ++i) cin >> b[i];
    vector<pair<int, int>> par(N + 1, {-1, -1});
    set<int> s;
    for (int i = 0; i <= N; ++i) s.insert(i);
    queue<int> q;
    vector<bool> vis(N + 1, 0);
    q.push(N);
    vis[N] = 1;
    while (q.size()) {
        int u = q.front();
        if (u == 0) break;
        q.pop();
        auto it = s.lower_bound(u - a[u]);
        vector<int> del;
        while (it != s.end() && *it <= u + b[u]) {
            int go = *it + b[*it];
            if (!vis[go]) {
                q.emplace(go);
                par[go] = {*it, u};
                vis[go] = 1;
            }
            del.emplace_back(*it);
            ++it;
        }
        for (int x : del) s.erase(x);
    } 
    if (par[0].first == -1) cout << -1 << '\n';
    else {
        vector<int> ans;
        int u = 0;
        for (; u != N; u = par[u].second) {
            ans.push_back(par[u].first);
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << '\n';
        for (auto x : ans) cout << x << ' ';
    }
    cout << '\n';
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