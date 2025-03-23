#include <bits/stdc++.h>
using namespace std;

#define int int64_t

int br[21][21];
int tin[21], low[21];
int c = 0;
vector<vector<int>> adj(21);
bool vis[21];
void bridge(int u, int p = -1) {
  vis[u] = 1;
  tin[u] = low[u] = ++c;
  for (auto& v : adj[u]) {
    if (v == p) continue;
    if (vis[v]) {
      low[u] = min(low[u], tin[v]);
    } else {
      bridge(v, u);
      low[u] = min(low[u], low[v]);
      if (low[v] > tin[u]) {
        br[v][u] = br[u][v] = 1;
      }
    }
  }
}

void solve() {
  int N, M;
  cin >> N >> M;
  for (int i = 0; i < M; ++i) {
    int u, v;
    cin >> u >> v;
    --u, -- v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }
  if (adj[0].size() == 1) {
    cout << -1 << '\n';
    return;
  }
  bridge(0);
  int ans = 1ll << 59;
  int a = 0;
  for (int i = 1; i < (1 << (N - 1)) - 1; ++i) {
    a++;
    int x = 0;
    for (int j = 1; j < N; ++j) {
      bool p = (1 << j) & (i << 1);
      for (auto& v : adj[j]) {
        if (v == 0) continue;
        bool p2 = (1 << v) & (i << 1);
        if (p ^ p2 && br[j][v]) {
          x = -1;
          break;
        }
        x += p ^ p2;
      }
      if (x == -1) break;
    }
    if (x == -1) continue;
    assert((x & 1) == 0);
    ans = min(ans, x / 2);
  }
  cout << a << '\n';
  if (ans == (1ll << 59)) ans = -1;
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