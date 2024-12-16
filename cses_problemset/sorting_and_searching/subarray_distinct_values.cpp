#include <bits/stdc++.h>
using namespace std;

template<typename... T>
void dbg(T&&... args) { ((cout << args << " "), ...); cout << '\n';}

#define int long long

constexpr int MOD = 1e9+7;
constexpr int MAX = 2e5+1;

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    for (int& x : a) cin >> x;
    set<int> s;
    int l = 0, r = 0, ans = N * (N + 1) / 2;
    map<int, int> mp;
    while (r < N) {
        s.emplace(a[r]);
        ++mp[a[r]];
        while (s.size() > K) {
            --mp[a[l]];
            if (mp[a[l]] == 0) {
                s.erase(a[l]);
            }
            ++l;
        }
        ans -= l;
        ++r;
    }
    cout << ans << '\n'; 
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