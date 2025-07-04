#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

constexpr int MAX = 2e5 + 1;
array<int, 3> queries[MAX];
int arr[MAX];
int ans[MAX];
int freq[MAX];

void solve() {
  int N, Q;
  cin >> N >> Q;
  map<int, int> mp;
  for (int i = 0; i < N; ++i) {
    cin >> arr[i];
    mp[arr[i]] = 1;
  }
  int c = 0;
  for (auto& [x, y] : mp) {
    y = c++;
  }
  for (int i = 0; i < N; ++i) {
    arr[i] = mp[arr[i]];
  }
  for (int i = 0; i < Q; ++i) {
    cin >> queries[i][1] >> queries[i][2];
    queries[i][1]--, queries[i][2]--;
    queries[i][0] = i;
  }
  int block = sqrt(N);
  sort(queries, queries + Q, [&](array<int, 3>& a, array<int, 3>& b){
    int block_a = a[1] / block;
    int block_b = b[1] / block;
    if (block_a != block_b) {
      return block_a < block_b;
    }
    return a[2] < b[2];
  });
  int lp = 0, rp = -1, cnt = 0;
  auto add = [&](int x) {
    if (++freq[x] == 1) {
      cnt++;
    }
  };
  auto del = [&](int x) {
    if (--freq[x] == 0) {
      cnt--;
    }
  };
  for (int q = 0; q < Q; ++q) {
    auto [i, l, r] = queries[q];
    while (lp < l) {
      del(arr[lp++]);
    }
    while (lp > l) {
      add(arr[--lp]);
    } 
    while (rp < r) {
      add(arr[++rp]);
    }
    while (rp > r) {
      del(arr[rp--]);
    }
    ans[i] = cnt;
  }
  for (int i = 0; i < Q; ++i) {
    cout << ans[i] << '\n';
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