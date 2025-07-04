#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {

  int tc = 30;
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  int mn = 1;
  int mx = 2e5 + 1;
  int size[29] = {4, 7, 11, 145, 1932, 5743, 11324, 23485, 39423, 53242, 
                  71321, 80213, 89427, 101234, 110324, 127436, 134573, 139523, 145673, 
                  151232, 166289, 173128, 183213, 191311, 200000, 200000, 200000, 200000, 200000};
  int worst = 510510; // 2 * 3 * 5 * 7 * 11 * 13 * 17
  for (int i = 0; i < 29; ++i) {
    int n = size[i];
    string s = "input";
    s += to_string(i);
    s += ".txt";
    ofstream o(s); 
    o << n << '\n';
    for (int i = 0; i < n; ++i) {
      int x = rng() % (mx - 1) + 1;
      o << x << ' ';
      assert(x < mx);
    }
    mn = n;
  }
  string s = "input";
  s += to_string(tc - 1);
  s += ".txt";
  ofstream o(s);
  o << 200000 << '\n';
  for (int i = 0; i < 200000; ++i) {
    int b = rng() % (3);
    if (b <= 1) {
      o << worst << ' ';
    } else {
      int x = rng() % (mx - 1) + 1;
      o << x << ' ';
    }
  }
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