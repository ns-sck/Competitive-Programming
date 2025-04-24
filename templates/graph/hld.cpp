vector<int> prh, depth, heavy, head, pos;
int t;

int hld_dfs(int u) {
  int size = 1;
  int mx = 0;
  for (int& eid : adj[v]) {
    int v = edges[eid].from ^ edges[eid].to ^ u;
    if (v != prh[u]) {
      prh[v] = u;
      depth[v] = depth[u] + 1;
      int c = hld_dfs(v);
      size += c;
      if (c > mx) {
        mx = c, heavy[u] = v;
      }
    }
  }
  return size;
}

void decompose(int u, int h) {
  head[u] = h, pos[u] = t++;
  if (heavy[u] != -1) {
    decompose(heavy[u], h);
    for (int& eid : adj[u]) {
      int v = edges[eid].from ^ edges[eid].to ^ u;
      if (v != prh[u] && v != heavy[u]) {
        decompose(v, v);
      }
    }
  }
}

void hld() {
  prh = vector<int>(n);
  depth = vector<int>(n);
  heavy = vector<int>(n, -1);
  head = vector<int>(n);
  pos = vector<int>(n);
  t = 0;
  hld_dfs(0);
  decompose(0, 0);
}

int query(int a, int b, SimpleSegmentTree& st) {
  int res = 0;
  for (; head[a] != head[b]; b = prh[head[b]]) {
    if (depth[head[a]] > depth[head[b]]) {
      swap(a, b);
    }
    int cur_mx = st.query(pos[head[b]], pos[b]);
    res = max(res, cur_mx);
  }
  if (depth[a] > depth[b]) {
    swap(a, b);
  }
  int last_mx = st.query(pos[a], pos[b]);
  res = max(res, last_mx);
  return res;
}