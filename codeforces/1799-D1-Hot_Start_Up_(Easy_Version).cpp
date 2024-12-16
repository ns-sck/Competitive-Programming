#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> arr(N + 1), cold(K + 1), hot(K + 1);
    for (int i = 1; i <= N; ++i) cin >> arr[i];
    for (int i = 1; i <= K; ++i) cin >> cold[i];
    for (int i = 1; i <= K; ++i) cin >> hot[i];
    vector<vector<int>> dp(N + 1, vector<int>(N + 1, 1ll << 61));
    dp[1][0] = dp[0][1] = cold[arr[1]];
    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j <= N; ++j) {
            if (i > j) {
                if (i == j + 1) {
                    for (int k = 0; k < j; ++k) {
                        dp[i][j] = min(dp[i][j], dp[k][j] + (arr[i] == arr[k] ? hot[arr[i]] : cold[arr[i]]));
                    }
                } else {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j] + (arr[i] == arr[i - 1] ? hot[arr[i]] : cold[arr[i]]));
                }
            } else if (i < j) {
                if (i == j - 1) {
                    for (int k = 0; k < i; ++k) {
                        dp[i][j] = min(dp[i][j], dp[i][k] + (arr[j] == arr[k] ? hot[arr[j]] : cold[arr[j]]));
                    }
                } else {
                    dp[i][j] = min(dp[i][j], dp[i][j - 1] + (arr[j] == arr[j - 1] ? hot[arr[j]] : cold[arr[j]]));
                }
            }
        }
    }
    int ans = 1ll << 61;
    for (int i = 0; i < N; ++i) {
        ans = min({ans, dp[i][N], dp[N][i]});
    }
    cout << ans << '\n';
}

signed main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}