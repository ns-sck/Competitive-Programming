#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t

void solve() {
  int N;
  cin >> N;
  set<int> s, fix;
  for (int i = 1; i <= N; ++i) {
    s.insert(i);
  }
  vector<int> q(N + 1);
  auto ask = [&](int x, set<int>& s) {
    cout << "? " << x << ' ' << s.size() + fix.size() << ' ';
    for (int y : s) {
      cout << y << ' ';
    }
    for (int y : fix) {
      cout << y << ' ';
    }
    cout << '\n';
    cout.flush();
    int d;
    cin >> d;
    return d;
  };
  int best = 0, node = 0;
  for (int i = 1; i <= N; ++i) {
    int d = ask(i, s);
    q[i] = d;
    if (d > best) {
      best = d;
      node = i;
    }
  }
  vector<int> ans(best + 1);
  for (int i = 0; i < N; ++i) {
    int x = *s.begin();
    s.erase(x);
    int d = ask(node, s);
    if (d < best) {
      fix.insert(x);
      ans[d - 1] = x;
    } 
  }
  cout << "! " << fix.size() << ' ';
  vector<int> path(fix.begin(), fix.end());
  sort(path.begin(), path.end(), [&](int i, int j){
    return q[i] >= q[j];
  });
  for (int& x : path) cout << x << ' ';
  cout << '\n';
  cout.flush();
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}