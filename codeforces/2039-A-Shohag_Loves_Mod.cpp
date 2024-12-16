#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int N;
    cin >> N;
    cout << 1 << ' ';
    for (int i = 2; i <= N; ++i) {
        cout << 2 * i - 1 << ' ';
    }
    cout << '\n';
}

signed main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}