// https://cses.fi/problemset/task/2086

#include <bits/stdc++.h>
using namespace std;

#define int int64_t

constexpr int MAX = 3e3 + 1;
constexpr int INF = 1ll << 61;
int pref[MAX];
int dp[MAX][MAX];

void dnc(int k, int left, int right, int optl, int optr) {
  if (left > right) return;
  int mid = (left + right) / 2;
  pair<int, int> best = {INF, left};
  for (int i = optl; i < min(mid, optr + 1); ++i) {
    int sum = pref[mid] - pref[i];
    best = min(best, {sum * sum + dp[k - 1][i], i});
  }
  dp[k][mid] = best.first;
  int opt = best.second;
  dnc(k, left, mid - 1, optl, opt);
  dnc(k, mid + 1, right, opt, optr);
}

void solve() {
  int N, K;
  cin >> N >> K;
  for (int i = 1; i <= N; ++i) {
    cin >> pref[i];
    pref[i] += pref[i - 1];
  }
  for (int i = 1; i <= N; ++i) {
    dp[0][i] = INF;
  }
  for (int i = 1; i <= K; ++i) {
    dnc(i, 1, N, 0, N - 1);
  }
  cout << dp[K][N] << '\n';
}

signed main () {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}