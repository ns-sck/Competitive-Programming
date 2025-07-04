#include <bits/stdc++.h>
using namespace std;

template <typename... T>
void dbg(T&&... args) {
  ((cout << args << " "), ...);
  cout << '\n';
}

#define int long long

constexpr int MOD = 1e9 + 7;
constexpr int MAX = 2e5 + 1;

void solve() {
  int N;
  cin >> N;
  vector<array<int, 3>> pr(N);
  for (int i = 0; i < N; ++i) {
    cin >> pr[i][1] >> pr[i][0] >> pr[i][2];
  }
  sort(pr.begin(), pr.end());
  set<pair<int, int>> s;
  int ans = 0;
  for (int i = 0; i < N; ++i) {
    auto [end, st, rw] = pr[i];
    auto it = s.lower_bound({st, -1});
    if (it == s.begin()) {
      ans = max(ans, rw);
      s.emplace(end, ans);
    } else {
      --it;
      ans = max(ans, it->second + rw);
      s.emplace(end, ans);
    }
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  // cin >> t;
  while (t--) solve();

  return 0;
}