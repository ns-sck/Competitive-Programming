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
  string s1, s2;
  cin >> s1 >> s2;
  int len1 = s1.length(), len2 = s2.length();
  vii dp(len1 + 1, vi(len2 + 1, 0));
  for (int i = 0; i <= len1; ++i) dp[i][0] = i;
  for (int i = 0; i <= len2; ++i) dp[0][i] = i;
  for (int i = 1; i <= len1; ++i) {
    for (int j = 1; j <= len2; ++j) {
      dp[i][j] = 1e9;
      if (s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
      dp[i][j] =
          min({dp[i][j] - 1, dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]}) + 1;
    }
  }
  cout << dp[len1][len2] << '\n';
  return 0;
}
