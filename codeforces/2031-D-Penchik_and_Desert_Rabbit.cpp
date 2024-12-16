#include <bits/stdc++.h>
using namespace std;

template<typename... T>
void dbg(T&&... args) { ((cout << args << " "), ...); cout << '\n';}

#define int long long

constexpr int MOD = 1e9+7;
constexpr int MAX = 5e2+1;

vector<int> par;
vector<int> sz;

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

void solve() {
    int N; cin >> N;
    sz.assign(N + 1, 1);
    par.assign(N + 1, 1);
    for (int i = 0; i < N; ++i) par[i] = i;
    vector<int> a(N);
    for (int& x : a) cin >> x;
    set<pair<int, int>> s;
    s.emplace(a[0], 0);
    for (int i = 1; i < N; ++i) {
        auto it = s.upper_bound({a[i], i});
        if (it == s.end()) {
            s.emplace(a[i], i);
            continue;
        }
        vector<set<pair<int, int>>::iterator> del;
        int mx = a[i], mxidx = i;
        while (it != s.end()) {
            int u = it->first, idx = it->second;
            if (u >= mx) {
                mx = u;
                mxidx = idx;
            }
            uni(idx, i);
            del.emplace_back(it);
            ++it;
        }
        for (auto it : del) {
            if (it->first == mx && it->second == mxidx) continue;
            s.erase(it);
        }
        if (mx = a[i] && mxidx == i) s.emplace(a[i], i);
    }
    map<int, int> mp;
    for (int i = 0; i < N; ++i) {
        int p = find(i);
        mp[p] = max(mp[p], a[i]);
    }
    for (int i = 0; i < N; ++i) {
        cout << mp[par[i]] << " \n"[i == N - 1];
    }
}

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}