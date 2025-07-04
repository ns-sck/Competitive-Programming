#include <bits/stdc++.h>
using namespace std;

#define int int64_t
constexpr int MOD = 1e9 + 7;

template <typename T>
struct BIT {
  std::vector<T> bit;
  int n;
  BIT(T size) {
    n = size;
    bit.assign(n + 1, 0);
  }

  void update(int idx, T delta) {
    while (idx <= n) {
      bit[idx] += delta;
      bit[idx] %= MOD;
      idx += idx & -idx;
    }
  }

  T query(int idx) {
    T sum = 0;
    while (idx > 0) {
      sum += bit[idx];
      sum %= MOD;
      idx -= idx & -idx;
    }
    return sum;
  }

  T range(int l, int r) {
    return query(r) - query(l - 1);
  }
};

void solve() {
  int N;
  cin >> N;
  vector<int> arr(N);
  map<int, int> mp;
  for (int i = 0; i < N; ++i) {
    cin >> arr[i];
    mp[arr[i]] = 1;
  }
  int c = 0;
  for (auto& [x, y] : mp) {
    y = ++c;
  }
  BIT<int> bit(N + 1);
  int ans = 0;
  for (int i = 0; i < N; ++i) {
    int add = 1 + bit.query(mp[arr[i]] - 1);
    ans = (ans + add) % MOD;
    bit.update(mp[arr[i]], add);
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