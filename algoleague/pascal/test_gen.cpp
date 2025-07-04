#include <bits/stdc++.h>
using namespace std;

#define int int64_t

constexpr int MAX = 1e6 + 1;

void solve() {
  int tc = 28;
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  int mn = 1;
  int mx = 5e6 + 1;
  int Q[30] = {0,      26,     30,     40,     100,    145,    500,    768,
               1600,   2600,   4900,   7400,   1100,   1600,   2700,   4100,
               14000,  32435,  58238,  91243,  123123, 145182, 194128, 200000,
               200000, 200000, 200000, 200000, 200000, 200000};
  auto get = [&](int a, int b) {
    int x = rng();
    return a + (x % (b - a + 1));
  };
  int arr[22];
  for (int i = 0; i < 22; ++i) {
    arr[i] = (1 << (i + 2)) - 1;
  }
  while (tc < 30) {
    string str = "input";
    if (tc < 10) str += '0';
    str += to_string(tc);
    str += ".txt";
    ofstream out(str);
    int mx = 1e7;
    out << Q[tc] << '\n';
    while (Q[tc]--) {
      int A = get(1, pow(tc, 6));
      int B = get(1, pow(tc, 6));
      int x = rng() % 2;
      int L = x ? get(2, min(mx, 17 * (int) pow(tc, 5))) : arr[rng() % 22];
      int R = x ? get(L, min(mx, 17 * (int) pow(tc, 5))) : arr[rng() % 22];
      while (R < L) {
        R = arr[rng() % 22];
      }
      out << A << ' ' << B << ' ' << L << ' ' << R << '\n';
    }
    tc++;
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}