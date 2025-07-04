#include <bits/stdc++.h>
using namespace std;

#define int int64_t

double dp[101][101][101];

// codeforces.com/contest/540/submission/316150730

// this function solves only for rock, by giving inputs
// in different order, we can solve for scissors and paper too
double rec(int r, int s, int p) {
  // no rook left, winning possiblity = 0;
  if (r == 0) {
    return 0;
  }
  // only rocks left, 100% win
  if (s == 0 && p == 0) {
    return dp[r][s][p] = 1;
  }
  // if we calculate the winning possiblity of having
  // r rocks, s scissors and p papers, don't need to calculate it again
  if (dp[r][s][p] != -1) {
    return dp[r][s][p];
  }
  // number of combinations of having rock vs paper
  double rr = r * p;
  // number of combinations of having scissors vs rock
  double ss = s * r;
  // number of combinations of having paper vs scissors
  double pp = p * s;
  // total number of combinations
  double total = rr + ss + pp;
  dp[r][s][p] = 0;
  // (the possiblity of having paper vs scissors) * (result of dp[r][s][p - 1])
  if (p > 0) {
    dp[r][s][p] += (pp / total) * rec(r, s, p - 1);
  }
  // (the possiblity of having scissors vs rock) * (result of dp[r][s - 1][p])
  if (s > 0) {
    dp[r][s][p] += (ss / total) * rec(r, s - 1, p);
  }
  // (the possiblity of having rock vs paper) * (result of dp[r - 1][s][p])
  dp[r][s][p] += (rr / total) * rec(r - 1, s, p);
  return dp[r][s][p];
}

void solve() {
  int R, S, P;
  cin >> R >> S >> P;
  fill ((double*) dp, (double*) dp + 101 * 101 * 101, -1);
  cout << setprecision(12) << rec(R, S, P) << ' ';
  fill ((double*) dp, (double*) dp + 101 * 101 * 101, -1);
  cout << setprecision(12) << rec(S, P, R) << ' ';
  fill ((double*) dp, (double*) dp + 101 * 101 * 101, -1);
  cout << setprecision(12) << rec(P, R, S) << '\n';
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