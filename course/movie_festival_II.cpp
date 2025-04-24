#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int N, K;
  cin >> N >> K;
  vector<pair<int, int>> arr(N);
  for (int i = 0; i < N; ++i) {
    int start, end;
    cin >> start >> end;
    arr[i] = {end, start};
  }
  sort(arr.begin(), arr.end());
  multiset<int> ms;
  int ans = 0;
  for (auto [end, start] : arr) {
    if (ms.size() < K) {
      ms.insert(end);
      ++ans;
      continue;
    }
    auto it = ms.upper_bound(start);
    if (it == ms.begin()) continue;
    --it;
    ms.erase(it);
    ++ans;
    ms.insert(end);
  }
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