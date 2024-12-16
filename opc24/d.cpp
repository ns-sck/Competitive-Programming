#include <bits/stdc++.h>

#define int long long
#define endl '\n'

using namespace std;

constexpr int MOD = 998244353;
constexpr int p = 127;
constexpr int p2 = 151;
int hashes[3001][3001];
int hashes2[3001][3001];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n; cin >> n;
  string s; cin >> s;
  map<pair<int, int>, int> mp;
  map<pair<int, int>, int> prev;
  vector<int> pows(n + 1);
  vector<int> pows2(n + 1);
  pows[0] = 1;
  pows2[0] = 1;
  for (int i = 1; i <= n; ++i) {
    pows[i] = pows[i-1] * p % MOD;
    pows2[i] = pows2[i-1] * p2 % MOD;
  }
  for (int i = 0; i < n; ++i) {
    hashes[1][i] = s[i];
    hashes2[1][i] = s[i];
  }
  vector<int> ans(n);
  for (int i = 2; i <= n; ++i) {
    for (int j = 0; j <= n - i; ++j) {
      hashes[i][j] = (hashes[i - 1][j] + (pows[i - 1] * s[j + i - 1] % MOD)) % MOD;
      hashes2[i][j] = (hashes2[i - 1][j] + (pows2[i - 1] * s[j + i - 1] % MOD)) % MOD;
      if (prev[{hashes[i - 1][j], hashes2[i - 1][j]}] != s[j + i - 1]) {mp[{hashes[i - 1][j], hashes2[i - 1][j]}]++; prev[{hashes[i - 1][j], hashes2[i - 1][j]}] = s[j + i - 1];}
    }
    for (auto [x, y] : mp) {
      ans[i - 1] = max(ans[i - 1], y);
    }
    mp.clear();
    prev.clear();
  }
  char r = '+';
  int f = 0;
  for (auto c : s) if (c != r) {f++; r = c;}
  ans[0] = f;
  for (auto i : ans) cout << i << ' ';

  return 0;
}