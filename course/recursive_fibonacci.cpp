#include <bits/stdc++.h>
using namespace std;

#define int int64_t

// 0 1 1 2 3 5 8 13 21 34 55 89...
vector<int> memo(1000000, -1);

int fib(int n) {
  if (n <= 1) {
    return n;
  }
  if (memo[n] != -1) {
    return memo[n];
  }
  return memo[n] = fib(n - 2) + fib(n - 1);
}

void solve() {
  int N;
  cin >> N;
  cout << fib(N) << '\n';
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