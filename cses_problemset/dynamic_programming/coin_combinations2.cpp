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
    int n, x; cin >> n >> x;
    vi v(n);
    vi dp(x+1);
    dp[0] = 1;
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= x; ++j) {
            if (j - v[i] >= 0)
                dp[j] = (dp[j-v[i]] + dp[j]) % MOD;
        }
    }
    cout << dp[x];
    return 0;
}
