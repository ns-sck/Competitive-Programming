#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t
constexpr int MAX = 2e5 + 1;
vector<int> spf(MAX);
vector<int> prs;

void sieve() {
  for (int i = 2; i < MAX; ++i) {
    if (spf[i] == 0) {
      spf[i] = i;
      prs.push_back(i);
    }
    for (int j = 0; i * prs[j] < MAX; ++j) {
      spf[i * prs[j]] = prs[j];
      if (prs[j] == spf[i]) {
        break;
      }
    }
  }
}

int vis[MAX];

void solve() {
  int N;
  cin >> N;
  vector<array<int, 2>> a(N);
  for (int i = 0; i < 2 * N; ++i) {
    cin >> a[i % N][i / N];
  }
  constexpr int inf = 1ll << 61;
  priority_queue<array<int, 2>, vector<array<int, 2>>, greater<>> pq;
  int two1 = inf, two2 = inf;
  vector<int> cur;
  for (int i = 0; i < N; ++i) {
    if (a[i][0] & 1) {
      if (a[i][1] <= two1) {
        two2 = two1;
        two1 = a[i][1];
      } else if (a[i][1] < two2) {
        two2 = a[i][1];
      }
    } else {
      two2 = two1;
      two1 = 0;
    }
    int x = a[i][0];
    while (x > 1) {
      int y = spf[x];
      if (vis[y]) {
        cout << 0 << '\n';
        for (int& c : cur) vis[c] = 0;
        return;
      }
      vis[y] = 1;
      cur.push_back(y);
      while (x % y == 0) x /= y;
      pq.push({y, y});
    }
  }
  sort(a.begin(), a.end());
  int ans = two1 + two2;
  for (int i = 0; i < N; ++i) {
    vector<array<int, 2>> save;
    while (pq.size() && pq.top()[0] <= a[i][0]) {
      auto [x, y] = pq.top();
      pq.pop();
      if (__gcd(y, a[i][0]) > 1) save.push_back({(a[i][0] + y - 1) / y * y, y}); 
      else pq.push({(a[i][0] + y - 1) / y * y, y});
    }
    if (pq.size()) ans = min(ans, (pq.top()[0] - a[i][0]) * a[i][1]);
    for (auto a : save) pq.push(a);
  }
  for (int& c : cur) vis[c] = 0;
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  sieve();
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}