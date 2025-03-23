#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int Q;
  cin >> Q;
  vector<int> arr = {0};
  while (Q--) {
    int q;
    cin >> q;
    if (q & 1) {
      int x;
      cin >> x;
      arr.emplace_back(arr.back() + x);
    } else {
      int n = arr.size();
      int lo = 1, hi = n - 2;
      double ans = 0;
      while (lo <= hi) {
        int mi = (lo + hi) >> 1;
        int tot = arr[mi] + arr[n - 1] - arr[n - 2];
        double mean = (double) tot / (mi + 1);
        ans = max(ans, (double) arr[n - 1] - mean - arr[n - 2]);
        if ((double) arr[mi] - arr[mi - 1] > mean) {
          hi = mi - 1;
        } else {
          lo = mi + 1;
        }
      }
      // double ans2 = 0;
      // for (int i = 1; i < n - 1; ++i) {
      //   int tot = arr[i] + arr[n - 1] - arr[n - 2];
      //   double mean = (double) tot / (i + 1);
      //   ans2 = max(ans2, arr[n - 1] - mean - arr[n - 2]);
      // }
      cout << fixed << setprecision(6) << ans << '\n';
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