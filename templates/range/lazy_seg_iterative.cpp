#include <bits/stdc++.h>
using namespace std;

#define int int64_t

constexpr int inf = 1ll << 61;

struct Info {
  int sum;
  int mx;
  int mn;

  Info() : sum(0), mn(inf), mx(-inf) {}
  Info(int x) : sum(x), mn(x), mx(x) {}

  Info unite(const Info& b) {
    Info res;
    res.sum = sum + b.sum;
    res.mn = min(mn, b.mn);
    res.mx = max(mx, b.mx);
    return res;
  }
};

struct Tag {
  int put;
  int delta;

  Tag() : put(-1), delta(0) {}
};

struct LazySegmentTree {
  int n, h;
  vector<Info> infos;
  vector<Tag> tags;

  LazySegmentTree(vector<Info>& a) : n(a.size()) {
    h = log2(n);
    infos.resize(2 * n);
    tags.resize(2 * n);
    for (int i = 0; i < a.size(); ++i) {
      infos[i + n] = a[i];
    }
    for (int i = n - 1; i > 0; --i) {
      infos[i] = infos[i << 1].unite(infos[i << 1 | 1]);
    }
  } 

  Info query(int l, int r) {
    l += n, r += n;
    push(l);
    push(r);
    Info resL, resR;
    for (; l <= r; l >>= 1, r >>= 1) {
      if (l & 1) resL = resL.unite(infos[l++]);
      if (~r & 1) resR = infos[r--].unite(resR);
    }
    return resL.unite(resR);
  }

  void push(int p)  {
    int k = n >> 1;
    for (int i = h; i > 0; --i, k >>= 1) {
      int s = p >> i;
      if (tags[s].delta != 0) {
        apply(s << 1, tags[s].delta, k);
        apply(s << 1 | 1, tags[s].delta, k);
        tags[s].delta = 0;
      } else if (tags[s].put != -1) {
        apply(s << 1, tags[s].delta, k);
        apply(s << 1 | 1, tags[s].delta, k);
        tags[s].put = -1;
      }
    }
  }

  void apply(int i, int val, int rng) {
    infos[i].sum += val * rng;
    infos[i].mn += val;
    infos[i].mx += val;
    if (i < n) tags[i].delta += val;
    // infos[i].sum = val * rng;
    // infos[i].mn = val;
    // infos[i].mx = val;
    // if (i < n) tags[i].delta = val;
  }

  void modify(int l, int r, int val) {
    l += n, r += n;
    int k = 1;
    push(l);
    push(r);
    for (; l <= r; l >>= 1, r >>= 1, k <<= 1) {
      if (l & 1) {
        apply(l++, val, k);
      }
      if (~r & 1) {
        apply(r--, val, k);
      }
    }
  }

  void set(int l, int r, int val) {
    l += n, r += n;
    int k = 1;
    push(l);
    push(r);
    for (; l <= r; l >>= 1, r >>= 1, k <<= 1) {
      if (l & 1) {
        apply(l++, val, k);
      }
      if (~r & 1) {
        apply(r--, val, k);
      }
    }
  }
};

void solve() {
  int N, Q;
  cin >> N >> Q;
  vector<int> arr(N);
  vector<Info> infos(N);
  for (int i = 0; i < N; ++i) {
    cin >> arr[i];
    infos[i] = {arr[i]};
  }
  LazySegmentTree st(infos);
  while (Q--) {
    int q;
    cin >> q;
    if (q == 1) {
      int l, r, x;
      cin >> l >> r >> x;
      --l, --r;
      st.modify(l, r, x); 
    } else {
      int k;
      cin >> k;
      --k;
      cout << st.query(k, k).sum << '\n';
    }
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