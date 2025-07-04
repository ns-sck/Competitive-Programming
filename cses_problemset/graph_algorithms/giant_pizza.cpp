#include <bits/stdc++.h>
using namespace std;

#define int int64_t

int N, M;
vector<bool> vis;
vector<vector<int>> adj, rev;
vector<vector<int>> comps;
vector<bool> cyc;
 
void dfs(int u, vector<vector<int>>& G, vector<int>& output) {
  vis[u] = true;
  for (auto v : G[u]) {
    if (!vis[v]) {
      dfs(v, G, output);
    }
  }
  output.push_back(u);
}
 
void scc() {
  rev = vector<vector<int>>(N);
  vis = vector<bool>(N);
  cyc = vector<bool>(N);
  vector<int> order;
  for (int i = 0; i < N; i++) {
    if (!vis[i]) {
      dfs(i, adj, order); 
    }
  }
  for (int i = 0; i < N; ++i) {
    for (int& j : adj[i]) {
      rev[j].push_back(i);
    }
  }
  vis.assign(N, 0);
  reverse(order.begin(), order.end());
  for (auto u : order) {
    if (vis[u]) continue;
    vector<int> comp;
    dfs(u, rev, comp);  
    sort(comp.begin(), comp.end());
    comps.push_back(comp);
  }
}

void solve() {
  cin >> M >> N;
  N <<= 1;
  adj = vector<vector<int>>(N);
  auto flip = [&](int i) {
    if (i >= N / 2) return i - N / 2;
    return i + N / 2;
  };
  vector<char> ans(N / 2, '?');
  while (M--) {
    char a, b;
    int x, y;
    cin >> a >> x >> b >> y;
    --x, --y;
    if (a == '-') x = flip(x);
    if (b == '-') y = flip(y);
    adj[flip(x)].push_back(y);
    adj[flip(y)].push_back(x);
  }
  scc();
  vector<int> g(N);
  int i = 0;
  for (auto& v : comps) {
    for (int& x : v) {
      g[x] = i;
    }
    ++i;
  }
  for (int i = 0; i < N / 2; ++i) {
    if (g[i] == g[flip(i)]) {
      cout << "IMPOSSIBLE\n";
      return;
    }
  }
  vector<bool> vis(N);
  int have = 0;
  vector<int> cur;
  auto dfs = [&](auto&& self, int u, int p) -> void {
    vis[u] = 1;
    cur.push_back(u);
    if (vis[u] && vis[flip(u)]) have++;
    for (int& v : adj[u]) {
      if (v == p || vis[v]) continue;
      self(self, v, u);
    }
  };
  auto dfs2 = [&](auto&& self, int u, int p) -> void {
    if (u >= N / 2) ans[flip(u)] = '-';
    else ans[u] = '+';
    for (int& v : adj[u]) {
      if (v == p || ans[v] != '?') continue;
      self(self, v, u);
    }
  };
  vector<int> arr(N);
  iota(arr.begin(), arr.end(), 0);
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  shuffle(arr.begin(), arr.end(), rng);
  for (int& i : arr) {
    if (ans[min(i, flip(i))] != '?') continue;
    int x = have;
    cur.resize(0);
    vis.assign(N, 0);
    dfs(dfs, i, -1);
    if (x == have) {
      for (int& u : cur) {
        if (u >= N / 2) {
          ans[flip(u)] = '-';
        } else {
          ans[u] = '+';
        }
      }
    } else {
      dfs2(dfs2, flip(i), -1);
    }
  }
  for (int i = 0; i < N / 2; ++i) {
    cout << ans[i] << " \n"[i == N / 2 - 1];
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