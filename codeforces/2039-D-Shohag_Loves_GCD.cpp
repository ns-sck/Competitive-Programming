#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int N, M;
    cin >> N >> M;
    vector<int> a(M);
    vector<int> ans(N + 1);
    for (int& x : a) cin >> x;
    sort(a.rbegin(), a.rend());
    for (int i = 2; i <= N; ++i) {
        if (!ans[i]) ans[i] = 1;
        for (int j = i + i; j <= N; j += i) {
            ans[j] = ans[i] + 1;
        }
    }
    int mx = *max_element(ans.begin(), ans.end());
    if (mx >= M) {
        cout << -1 << '\n';
    } else {
        for (int i = 1; i <= N; ++i) {
            cout << a[ans[i]] << " \n"[i == N];
        }
    }
}

signed main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}