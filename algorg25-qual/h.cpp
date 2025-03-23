#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int N;
  cin >> N;
  vector<int> arr(N);
  for (int& x : arr) cin >> x;
  vector<int> sor = arr;
  sort(sor.begin(), sor.end());
  int ans = 1 << 30;
  auto dfs = [&](auto&& self, int i, int j, int op, vector<int> a) -> void {
    if (i == j) {
      ans = min(ans, op);
      return;
    }
    int k = N - (j - i) - 1;
    int el = sor[k];
    int where = - 1;
    for (int z = 0; z < N; ++z) {
      if (a[z] == el) {
        where = z;
        break;
      }
    }
    if (a[i] == el) {
      self(self, i + 1, j, op, a);
    } else {
      swap(a[i], a[where]);
      self(self, i + 1, j, op + 1, a);
      swap(a[i], a[where]);
    }
    if (a[j] == el) {
      self(self, i, j - 1, op, a);
    } else {
      swap(a[j], a[where]);
      self(self, i, j - 1, op + 1, a);
      swap(a[j], a[where]);
    }
  };
  dfs(dfs, 0, N - 1, 0, arr);
  cout << ans << '\n';
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