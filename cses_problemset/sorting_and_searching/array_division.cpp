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
    int t = 0;
    for (int& x : a) cin >> x;
    for (int& x : a) t += x;
    int ans = t, lo = 0, hi = t;
    while (lo <= hi) {
        int mi = (lo + hi) / 2;
        int c = 1;
        t = 0;
        for (int i = 0; i < N; ++i) {
            if (a[i] > mi) {
                c = K + 1;
                break;
            }
            if (t + a[i] > mi) {
                t = a[i];
                ++c;
            } else {
                t += a[i];
            }
        }
        if (c <= K) {
            hi = mi - 1;
        } else if (c > K) {
            lo = mi + 1;
        }
    }
    cout << lo << '\n';
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