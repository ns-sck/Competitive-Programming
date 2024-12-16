#include <bits/stdc++.h>
using namespace std;

template<typename... T>
void dbg(T&&... args) { ((cout << args << " "), ...); cout << '\n';}

#define int long long

constexpr int MOD = 1e9+7;
constexpr int MAX = 2e5+1;

void solve() {
    string S; cin >> S;
    char mn = 'z', idx = 0;
    for (int i = 0; i < S.size(); ++i) {
        if (S[i] <= mn) {
            mn = S[i];
            idx = i;
        }
    }
    cout << mn << ' ';
    for (int i = 0; i < S.size(); ++i) {
        if (i == idx) continue;
        cout << S[i];
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