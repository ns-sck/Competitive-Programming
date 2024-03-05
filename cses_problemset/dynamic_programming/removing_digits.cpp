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
    int n; cin >> n;
    vi dp(n+1, 1e9);
    dp[n] = 0;
    for (int i = n; i >= 0; --i) {
        string s = to_string(i);
        for (int j = 0; j < s.length(); ++j) {
            int dig = s[j] - '0';
            dp[i-dig] = min(dp[i-dig], dp[i]+1);
        }
    }
    cout << dp[0];
    return 0;
}
