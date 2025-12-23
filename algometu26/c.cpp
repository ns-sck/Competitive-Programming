#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t

void solve() {
  string S;
  cin >> S;
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  auto get = [&]() {
    return rng() % 50;
  };
  for (int i = 0; i < 5e5; ++i) {
    int a = get(), b = get(), c = get(), d = get(), s = get(), m = max((unsigned) 1, get());
    vector<int> arr(S.size());
    arr[0] = s;
    for (int j = 1; j < S.size(); ++j) {
      int x = arr[j - 1];
      arr[j] = (a * x * x * x + b * x * x + c * x + d) % m;
    }
    bool bl = 1;
    for (int k = 0; k < S.size(); ++k) {
      if (S[k] != '?' && S[k] - '0' != arr[k]) bl = 0;
    }
    if (bl) {
      cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << s << ' ' << m << '\n';
      return;
    }
  }
  cout << "-1 -1 -1 -1 -1 -1\n";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}