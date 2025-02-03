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
    vector<int> mod(N);
    int ans = 0, t = 0;
    mod[0] = 1;
    for (int i = 0; i < N; ++i) {
        t += a[i];
        int m = t % N;
        if (t < 0) {
            if (t % N) m = N - abs(t % N);
        }
        ans += mod[m];
        ++mod[m];
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