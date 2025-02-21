#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<vector<int>>
#define mii map<int, int>
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
const int MOD = 1e9+7;

int32_t main() {

    ios;
    int a, b; cin >> a >> b;
    vii dp(a+1, vi(b+1));
    for (int i = 1; i <= a; ++i) {
        for (int j = 1; j <= b; ++j) {
            if (i^j)
                dp[i][j] = 1e9;
            for (int k = 1; k < i; ++k) {
                dp[i][j] = min(dp[i][j], dp[i-k][j] + dp[k][j] + 1);
            }
            for (int l = 1; l < j; ++l) {
                dp[i][j] = min(dp[i][j], dp[i][j-l] + dp[i][l] + 1);
            }
        }
    }
    cout << dp[a][b];
    return 0;
}
