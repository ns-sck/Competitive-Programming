#include <bits/stdc++.h>
using namespace std;

#define int int64_t

constexpr int INF = 1ll << 61;
int MOD;

#define lch i << 1
#define rch i << 1 | 1

struct Info {
  int id;
  int x;
  int y;
  int z;
  int t;

  Info() : id(INF), x(1), y(0), z(0), t(1) {}
  Info(int id, int x, int y, int z, int t) : id(id), x(x), y(y), z(z), t(t) {}

  Info unite(const Info& b) {
    Info res;
    Info me(*this), it = b;
    if (me.id > b.id) swap(me, it);
    res.id = min(me.id, it.id);
    res.x = (me.x * it.x + me.y * it.z) % MOD;
    res.y = (me.x * it.y + me.y * it.t) % MOD;
    res.z = (me.z * it.x + me.t * it.z) % MOD;
    res.t = (me.z * it.y + me.t * it.t) % MOD;
    return res;
  }

  // friend ostream& operator<<(ostream& os, const Info& info) {
  //   os << "sum: " << info.sum << ", min: " << info.mn << ", max: " << info.mx;
  //   return os;
  // }
};

struct SimpleSegmentTree {

  int n;
  vector<Info> info;
  SimpleSegmentTree(vector<Info>& a) : n(1 << (32 - __builtin_clz(a.size() - 1))) {
    info.resize(n << 1);
    for (int i = 0; i < a.size(); ++i) {
      info[i + n] = a[i];
    }
    for (int i = n - 1; i > 0; --i) {
      info[i] = info[lch].unite(info[rch]);
    }
  }

  // void apply(Info& a, int val) {
  //   a.sum += val;
  //   a.mn += val;
  //   a.mx += val;
  // }

  // void modify(int i, int val) {
  //   i += n;
  //   apply(info[i], val);
  //   i >>= 1;
  //   while (i >= 1) {
  //     info[i] = info[lch].unite(info[rch]);
  //     i >>= 1;
  //   }
  // }

  Info query(int l, int r) {
    l += n; 
    r += n;
    Info res; 
    vector<Info> v;
    while (l <= r) {
      if (l & 1) {
        v.emplace_back(info[l++]);
      }
      if (~r & 1) {
        v.emplace_back(info[r--]);
      } 
      l >>= 1, r >>= 1;
    }
    if (v.size() > 1) {
      sort(v.begin(), v.end(), [](Info a, Info b){
        return a.id < b.id;
      });
    }
    for (Info& i : v) {
      res = res.unite(i);
    }
    return res;
  }

  // int bs(int ql, int qr, int x, int i = 1, int nl = 0, int nr = -1) {
  //   if (nr == -1) nr = n - 1;
  //   if (nr < ql || nl > qr || info[i].sum < x) {
  //     return -1;
  //   }
  //   if (nl == nr) {
  //     return nr;
  //   } 
  //   int m = (nl + nr) >> 1;
  //   int res = bs(ql, qr, x, lch, nl, m);
  //   if (res != -1) {
  //     return res;
  //   }
  //   return bs(ql, qr, x, rch, m + 1, nr);
  // }
};

void solve() {
  cin >> MOD;
  int N, Q;
  cin >> N >> Q;
  vector<Info> infos(N);
  for (int i = 0; i < N; ++i) {
    int x, y, z, t;
    cin >> x >> y >> z >> t;
    infos[i] = {i, x, y, z, t};
  }
  SimpleSegmentTree st(infos);
  while (Q--) {
    int l, r;
    cin >> l >> r;
    --l, --r;
    Info in = st.query(l, r);
    cout << in.x << ' ' << in.y << '\n' << in.z << ' ' << in.t << '\n';  
    cout << '\n';
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