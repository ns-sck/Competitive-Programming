#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t
constexpr int MAX = 2e5 + 2;
vector<vector<int>> divs(MAX);

void init() {
  for (int i = 1; i <= MAX; ++i) {
    for (int j = i; j <= MAX; j += i) {
      divs[j].push_back(i);
    }
  }
}

void solve() {
  int N;
  string S;
  cin >> N >> S;
  for (int& x : divs[N]) {
    int d = 0, e = 0;
    vector<vector<char>> v(x);
    for (int i = 0; i < N; ++i) {
      v[i % x].push_back(S[i]);
    }
    for (int i = 0; i < x; ++i) {
      int b = count(v[i].begin(), v[i].end(), v[i][0]);
      int c = count(v[i].begin(), v[i].end(), v[i].back());
      if ((b + c != 2 * v[i].size()) && (max(b, c) != v[i].size() - 1)) d++;
      if (b + c != 2 * v[i].size()) e++;
    }
    if (d) continue;
    if (e < 2) {
      cout << x << '\n';
      return;
    } 
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  init();
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}