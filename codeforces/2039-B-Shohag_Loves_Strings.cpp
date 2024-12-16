#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    string S;
    cin >> S;
    if (S.size() == 1) {
        cout << -1 << '\n';
        return;
    }
    if (S[0] == S[1]) {
        cout << S.substr(0, 2) << '\n';
        return;
    }
    if (S.size() == 2) {
        cout << -1 << '\n';
        return;
    }
    int N = S.size();
    for (int i = 0; i < N - 2; ++i) {
        if (S[i + 2] != S[i]) {
            if (S[i] == S[i + 1]) {
                cout << S[i] << S[i] << '\n';
                return;
            } else if (S[i + 1] == S[i + 2]) {
                cout << S[i + 1] << S[i + 1] << '\n';
                return;
            } else {
                cout << S.substr(i, 3) << '\n';
                return;
            }
        }
    }
    cout << -1 << '\n';
}

signed main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}