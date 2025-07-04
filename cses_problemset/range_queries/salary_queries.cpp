#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,
                              tree_order_statistics_node_update>;

#define int int64_t

void solve() {
  int N, Q;
  cin >> N >> Q;
  oset<pair<int, int>> os;
  vector<int> arr(N);
  for (int i = 0; i < N; ++i) {
    cin >> arr[i];
    os.insert({arr[i], i + 1});
  }
  while (Q--) {
    char c;
    int x, y;
    cin >> c >> x >> y;
    if (c == '?') {
      int ans = os.order_of_key({y + 1, 0}) - os.order_of_key({x, 0});
      cout << ans << '\n';
    } else {
      --x;
      os.erase({arr[x], x + 1});
      arr[x] = y;
      os.insert({y, x + 1});
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