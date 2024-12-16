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
    map<int, int> mp;
    set<int> s = {a[0]};
    for (int i = 1; i < N; ++i) {
        auto it = s.lower_bound(a[i] + 2);
        if (it != s.end()) {
            cout << "NO\n";
            return;
        }
        s.insert(a[i]);
    }
    cout << "YES\n";
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