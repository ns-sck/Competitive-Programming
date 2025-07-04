#include <bits/stdc++.h>
using namespace std;

#define int int64_t
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
constexpr int MAX = 2e5;
int t = 29;

int get(int l, int r) {
  assert(l <= r);
  int x = l + rng() % (r - l);
  return x;
}

void solve() {
  string file = "input";
  if (t < 10) file += '0';
  file += to_string(t);
  file += ".txt";
  ofstream os(file);
  int tt = get(1, 10000);
  int a = get(1, 2);
  if (a == 1) {
    tt = max(1ll, tt / 100);
  }
  os << tt << '\n';
  for (int i = 0; i < tt; ++i) {
    string inp;
    int N = get(1, MAX / tt);
    for (int i = 0; i < N; ++i) {
      char c = 'a' + get(0, 26);
      inp += c;
    }
    string inpx = inp;
    while (inpx.size() + inp.size() <= N) {
      inpx += inp;
    } 
    os << inpx.size() << '\n' << inpx << '\n';
  }
}

signed main () {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  // int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  ofstream os("input29.txt");
  os << 1 << '\n';
  os << 200000 << '\n';
  string s;
  for (int i = 0; i < 200000; ++i) {
    s += 'a';
  }
  os << s << '\n';
  return 0;
}