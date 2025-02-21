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
    vi v(n, 0);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    
    vi dp (1e6+1, 1e9);
    dp[0] = 0;
    for (int i = 1; i < 1e6+1; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i - v[j] >= 0) {
                dp[i] = min(dp[i-v[j]] + 1, dp[i]);
            }    
        }
    }
    if (dp[x] == 1e9)
        cout << -1 << '\n';
    else {
        cout << dp[x];
    }
    return 0;
}
