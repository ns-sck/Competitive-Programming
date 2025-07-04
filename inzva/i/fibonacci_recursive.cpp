#include <bits/stdc++.h>
using namespace std;

#define int int64_t

vector<int> dp((int) 1e5, -1);

int fib(int n) {
  if (n <= 1) return n;
  if (dp[n] != -1) {
    // this number is calculated before, don't recurse from here again
    return dp[n];
  }
  return dp[n] = fib(n - 1) + fib(n - 2);
}

// 0 1 1 2 3 5 8 13 21 34 55 89 144 233 377
void solve() {
  cout << fib(50) << '\n';
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