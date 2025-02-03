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
    int n, k; 
    cin >> n >> k;
    vi p(n, 0);
    vi w(n, 0);
    for (int i = 0; i < n; ++i)
        cin >> w[i];
    for (int i = 0; i < n; ++i)
        cin >> p[i];
    
    vi dp(k+1, 0);

    for (int i = 0; i < n; ++i) {
        for (int j = w[i]; j <= k; ++j) {
            dp[j] = max(dp[j], dp[j-w[i]] + p[i]);
        }
    }
    cout << dp[k];
    return 0;
}