#include <bits/stdc++.h>
using namespace std;

struct TwoSatSolver {
  int n_vars;
  int n_vertices;
  vector<vector<int>> adj, adj_t;
  vector<bool> used;
  vector<int> order, comp;
  vector<bool> assignment;
  vector<int> ans;

  TwoSatSolver(int _n_vars) : ans(n_vars), n_vars(_n_vars), n_vertices(2 * n_vars), adj(n_vertices), adj_t(n_vertices), used(n_vertices), order(), comp(n_vertices, -1) {
      order.reserve(n_vertices);
  }
  void dfs1(int v) {
      used[v] = true;
      for (int u : adj[v]) {
          if (!used[u])
              dfs1(u);
      }
      order.push_back(v);
  }

  void dfs2(int v, int cl) {
      comp[v] = cl;
      for (int u : adj_t[v]) {
          if (comp[u] == -1)
              dfs2(u, cl);
      }
  }

  bool solve_2SAT() {
      order.clear();
      used.assign(n_vertices, false);
      for (int i = 0; i < n_vertices; ++i) {
          if (!used[i])
              dfs1(i);
      }

      comp.assign(n_vertices, -1);
      for (int i = 0, j = 0; i < n_vertices; ++i) {
          int v = order[n_vertices - i - 1];
          if (comp[v] == -1)
              dfs2(v, j++);
      }

      for (int i = 0; i < n_vertices; i += 2) {
          if (comp[i] == comp[i + 1])
              return false;
      }
      int start = -1;
      vector<bool> act(n_vertices);
      auto cheese = [&](auto&& self, int u) -> bool {
        if (act[u]) return true;
        act[u] = 1;
        if ((u ^ start) == 1) {
          return false;
        }
        bool b = 1;
        for (auto& v : adj[u]) {
          b &= self(self, v);
        }
        if (!b) return false;
        ans[u / 2] = (u & 1) ? 2 : 1;
        act[u] = 0;
        return true;
      };
      for (int i = 1; i < n_vertices; i += 2) {
        if (ans[i / 2]) continue;
        start = i;
        if (!cheese(cheese, i)) {
          start = i - 1;
          cheese(cheese, i - 1);
        }
      }
      return true;
  }

  void add_disjunction(int a, bool na, int b, bool nb) {
      // na and nb signify whether a and b are to be negated 
      a = 2 * a ^ na;
      b = 2 * b ^ nb;
      int neg_a = a ^ 1;
      int neg_b = b ^ 1;
      adj[neg_a].push_back(b);
      adj[neg_b].push_back(a);
      adj_t[b].push_back(neg_a);
      adj_t[a].push_back(neg_b);
  }

  // static void example_usage() {
  //     TwoSatSolver solver(3); // a, b, c
  //     solver.add_disjunction(0, false, 1, true);  //     a  v  not b
  //     solver.add_disjunction(0, true, 1, true);   // not a  v  not b
  //     solver.add_disjunction(1, false, 2, false); //     b  v      c
  //     solver.add_disjunction(0, false, 0, false); //     a  v      a
  //     assert(solver.solve_2SAT() == true);
  //     auto expected = vector<bool>(True, False, True);
  //     assert(solver.assignment == expected);
  // }
};

void solve() {
  int N, M;
  cin >> N >> M;
  TwoSatSolver solver(M);
  for (int i = 0; i < N; ++i) {
    char a, c;
    int b, d;
    cin >> a >> b >> c >> d;
    solver.add_disjunction(b - 1, a != '+', d - 1, c != '+');
  }
  if (solver.solve_2SAT()) {
    for (int i = 0; i < M; ++i) {
      cout << (solver.ans[i] == 2 ? '-' : '+');
    }
    cout << '\n';
  } else {
    cout << "IMPOSSIBLE\n";
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