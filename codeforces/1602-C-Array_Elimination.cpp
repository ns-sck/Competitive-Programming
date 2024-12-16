#include <bits/stdc++.h>
using namespace std;

template<typename... T>
void dbg(T&&... args) { ((cout << args << " "), ...); cout << '\n';}

#define int long long

constexpr int MOD = 1e9+7;
constexpr int MAX = 2e5+1;

void solve() {
    int N; cin >> N;
    vector<int> a(N), b(32);
    for (int& x : a) cin >> x;
    for (int i = 0; i < 31; ++i) {
        for (int& x : a) {
            if ((x >> i) & 1) ++b[i];
        }
    }
    for (int i = 1; i <= N; ++i) {
        bool bl = 1;
        for (int j = 0; j < 31 && bl; ++j) {
            if (b[j] % i) bl = 0;
        }
        if (bl) cout << i << ' ';
    }
    cout << '\n';
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