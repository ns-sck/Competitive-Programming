#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<vector<int>>
#define mii map<int, int>
#define ar array

const int MOD = 1e9 + 7;
const int mxN = 5e3;

pair<int, int> dp[mxN][mxN];

int32_t main() {
    int n;
    cin >> n;

    // GPT Solution
    vi v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    for (int i = 0; i < n; ++i)
        dp[i][i] = {v[i], 0};

    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i + len - 1 < n; ++i) {
            int j = i + len - 1;
            int pickLeft = dp[i + 1][j].second + v[i];
            int pickRight = dp[i][j - 1].second + v[j];
            if (pickLeft > pickRight)
                dp[i][j] = {pickLeft, dp[i + 1][j].first};
            else
                dp[i][j] = {pickRight, dp[i][j - 1].first};
        }
    }

    cout << dp[0][n - 1].first << "\n";
    return 0;
}