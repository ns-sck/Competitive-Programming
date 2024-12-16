#include <bits/stdc++.h>
using namespace std;

template<typename... T>
void dbg(T&&... args) { ((cout << args << " "), ...); cout << '\n';}

#define int long long

constexpr int MOD = 1e9+7;
constexpr int MAX = 2e5+1;

void solve() {
    int N; cin >> N;
    vector<int> a(N);
    for (int& x : a) cin >> x;
    set<pair<int, int>> s;
    for (int i = 0; i < N; ++i) {
        auto it = s.lower_bound({a[i], 0});
        if (it == s.begin()) {
            cout << 0 << ' ';
        } else {
            cout << prev(it)->second << ' ';
        }
        while (it != s.end()) s.erase(it++);
        s.emplace(a[i], i + 1);
    }
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