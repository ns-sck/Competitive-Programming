#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t
constexpr int MOD = 998244353;
constexpr int MAX = 3001;
int pos[MAX][MAX];
int neg[MAX][MAX];
int ps[MAX];
int ng[MAX];

void solve() {
  int N;
  cin >> N;
  vector<int> col(N);
  vector<vector<int>> adj(N);
  set<int> cols;
  vector<int> cnt(MAX);
  for (int i = 0; i < N; ++i) {
    cin >> col[i];
    cols.insert(col[i]);
    cnt[col[i]]++;
  }
  for (int i = 0; i < N - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int ans = 0, cur = 0;
  vector<int> pmx(N), nmx(N);
  auto add = [&](int& x, int y) {
    x = (x + y) % MOD;
  };
  auto f = [&](auto&& self, int u, int p) -> void {
    pos[u][1] = col[u] == cur;
    neg[u][1] = col[u] != cur;
    pmx[u] = pos[u][1] + 1;
    nmx[u] = neg[u][1] + 1;
    for (int& v : adj[u]) {
      if (v == p) continue;
      self(self, v, u);
      for (int i = 0; i < pmx[v]; ++i) {
        for (int j = 0; j < MAX && (!j || pos[u][j]); ++j) {
          add(ps[i + j], pos[v][i] * pos[u][j]);
          pmx[u] = max(pmx[u], i + j + 1);
        }
        for (int j = 0; j < MAX && (!j || neg[u][j]); ++j) {
          if (i >= j) add(ps[i - j], pos[v][i] * neg[u][j]);
          else add(ng[j - i], pos[v][i] * neg[u][j]);
        }
      }
      for (int i = 0; i < nmx[v]; ++i) {
        for (int j = 0; j < MAX && (!j || neg[u][j]) && i + j <= cnt[cur]; ++j) {
          add(ng[i + j], neg[v][i] * neg[u][j]);
          nmx[u] = max(nmx[u], i + j + 1);
        }
        for (int j = 0; j < MAX && (!j || pos[u][j]); ++j) {
          if (i > j) add(ng[i - j], neg[v][i] * pos[u][j]);
          else add(ps[j - i], neg[v][i] * pos[u][j]);
        }
      }
      for (int i = 0; i < pmx[u]; ++i) {
        add(pos[u][i], ps[i]);
        ps[i] = 0;
      }
      for (int i = 0; i < nmx[u]; ++i) {
        add(neg[u][i], ng[i]);
        ng[i] = 0;
      }
    }
  };
  for (int c : cols) {
    cur = c;
    f(f, 0, -1);
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < pmx[i]; ++j) add(ans, j ? pos[i][j] : 0), pos[i][j] = 0;
      for (int j = 0; j < nmx[i]; ++j) neg[i][j] = 0;
    }
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) solve();
  return 0;
}