#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,
                              tree_order_statistics_node_update>;

#define int int64_t

void solve() {
  oset<int> o;
  o.insert(3);
  o.insert(3); // no duplicate
  o.insert(4);
  o.insert(5);
  cout << o.order_of_key(5) << '\n';
  cout << *o.find_by_order(1) << '\n'; // returns iterator
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