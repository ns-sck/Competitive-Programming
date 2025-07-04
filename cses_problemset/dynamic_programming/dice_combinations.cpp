#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<vector<int>>
#define mii map<int, int>
#define ios                \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0)
const int MOD = 1e9 + 7;

int32_t main() {
  ios;
  int n;
  cin >> n;
  vi dp(n + 1, 0);
  dp[0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= 6; ++j) {
      if (i - j >= 0) {
        dp[i] = (dp[i] + dp[i - j]) % MOD;
      }
    }
  }
  cout << dp[n];
  return 0;
}
