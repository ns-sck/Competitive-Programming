#include <bits/stdc++.h>
using namespace std;

template<typename... T>
void dbg(T&&... args) { ((cout << args << " "), ...); cout << '\n';}

#define int long long

constexpr int MOD = 1e9+7;
constexpr int MAX = 2e5+1;

void solve() {
    int X, N;
    cin >> X >> N;
    vector<vector<int>> a;
    vector<int> next(N);
    priority_queue<array<int, 3>> pq;
    for (int i = 0; i < N; ++i) {
        int l; cin >> l;
        vector<int> v(l);
        for (int& x : v) cin >> x;
        int t = 0, mn = 0;
        for (int j = 0; j < l; ++j) {
            if (t + v[j] > 0) {
                pq.push({mn, t + v[j], i});
                next[i] = j + 1;
                break;
            }
            t += v[j];
            mn = min(mn, t);
        }
        a.emplace_back(v);
    }
    while (pq.size()) {
        auto [need, get, i] = pq.top();
        pq.pop();
        if (X + need < 0) break;
        X += get;
        int t = 0, mn = 0;
        for (int j = next[i]; j < a[i].size(); ++j) {
            if (t + a[i][j] > 0) {
                pq.push({mn, t + a[i][j], i});
                next[i] = j + 1;
                break;
            }
            t += a[i][j];
            mn = min(mn, t);
        }
    }
    cout << X << '\n';
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