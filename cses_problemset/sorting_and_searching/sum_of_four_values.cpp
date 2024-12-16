#include <bits/stdc++.h>
using namespace std;

template<typename... T>
void dbg(T&&... args) { ((cout << args << " "), ...); cout << '\n';}

#define int long long

constexpr int MOD = 1e9+7;
constexpr int MAX = 2e5+1;

void solve() {
    int N, X;
    cin >> N >> X;
    vector<int> a(N), b(N);
    for (int& x : a) cin >> x;
    iota(b.begin(), b.end(), 1);
    sort(b.begin(), b.end(), [&](int i, int j) {
        return a[i - 1] < a[j - 1];
    });
    sort(a.begin(), a.end());
    map<int, pair<int, int>> mp;
    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < i; ++j) {
            mp[a[i] + a[j]] = {j, i};
        }
        for (int j = i + 2; j < N; ++j) {
            int sum = a[i + 1] + a[j];
            if (mp.count(X - sum)) {
                cout << b[mp[X - sum].first] << ' ' << b[mp[X - sum].second] << ' ' << b[i + 1] << ' ' << b[j] << '\n';
                return;
            }
        }
    }
    cout << "IMPOSSIBLE";
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