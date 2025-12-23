#include <bits/stdc++.h>
using namespace std;

#define int int64_t

constexpr int MAX = 5e5;

void solve() {
  int tc = 30;
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  int mn = 1;
  int mx = 5e6 + 1;
  int mxN[30] = {5,      7,      30,      40,      100,     145,
                 500,    768,     1600,    2600,    4900,    7400,
                 19023,  26456,   37003,   50001,   73423,   97414,
                 101241,  128234,   145234,   164723,   179428,   191342,
                 200000, 200000,   200000,  200000,  200000,  200000};
  auto rnd = [&](int l, int r) {
    return l + (rng() % (r - l + 1));
  };
  for (int i = 0; i < tc; ++i) {
    string s = "input/input";
    if (i < 10) s += '0';
    s += to_string(i);
    s += ".txt";
    ofstream out(s);
    out << mxN[i] << '\n';
    unordered_set<int> st;
    while (st.size() < mxN[i]) {
      st.insert(rnd(2, min(mxN[i] * 3, MAX)));
    }
    for (auto& x : st) {
      out << x << ' ';
    }
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