#include <bits/stdc++.h>
using namespace std;

#define int int64_t

constexpr int INF = 1ll << 61;
int MOD = 1e20;

#define lch (i << 1)
#define rch (i << 1 | 1)

template <typename T>
vector<vector<T>> operator*(const vector<vector<T>>& a, const vector<vector<T>>& b) {
  if (a.empty() || b.empty()) {
    return {{}};
  }
  vector<vector<T>> c(a.size(), vector<T>(b[0].size()));
  for (int i = 0; i < static_cast<int>(c.size()); i++) {
    for (int j = 0; j < static_cast<int>(c[0].size()); j++) {
      c[i][j] = 0;
      for (int k = 0; k < static_cast<int>(b.size()); k++) {
        c[i][j] += a[i][k] * b[k][j];
        c[i][j] %= MOD;
      }
    }
  }
  return c;
}

template <typename T>
vector<vector<T>>& operator*=(vector<vector<T>>& a, const vector<vector<T>>& b) {
  return a = a * b;
}

template <typename T, typename U>
vector<vector<T>> power(const vector<vector<T>>& a, const U& b) {
  assert(b >= 0);
  vector<U> binary;
  U bb = b;
  while (bb > 0) {
    binary.push_back(bb & 1);
    bb >>= 1;
  }
  vector<vector<T>> res(a.size(), vector<T>(a.size()));
  for (int i = 0; i < static_cast<int>(a.size()); i++) {
    res[i][i] = 1;
  }
  for (int j = (int) binary.size() - 1; j >= 0; j--) {
    res *= res;
    if (binary[j] == 1) {
      res *= a;
    }
  }
  return res;
}

struct Info {
  int sum;
  int mn;
  int mx;

  Info() : sum(0), mn(INF), mx(-INF) {}
  Info(int x) : sum(x), mn(x), mx(x) {}

  Info unite(const Info& b) {
    Info res;
    res.sum = __gcd(sum, b.sum);
    res.mn = min(mn, b.mn);
    res.mx = max(mx, b.mx);
    return res;
  }
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

  void apply(Info& a, int val) {
    a.sum += val;
    a.mn += val;
    a.mx += val;
  }

  void modify(int i, int val) {
    i += n;
    apply(info[i], val);
    i >>= 1;
    while (i >= 1) {
      info[i] = info[lch].unite(info[rch]);
      i >>= 1;
    }
  }

  Info query(int l, int r) {
    l += n; 
    r += n;
    Info res; 
    while (l <= r) {
      if (l & 1) {
        res = res.unite(info[l++]);
      }
      if (~r & 1) {
        res = res.unite(info[r--]);
      } 
      l >>= 1, r >>= 1;
    }
    return res;
  }

  int bs(int ql, int qr, int x, int i = 1, int nl = 0, int nr = -1) {
    if (nr == -1) nr = n - 1;
    if (nr < ql || nl > qr || info[i].mx < x) {
      return -1;
    }
    if (nl == nr) {
      return nr;
    } 
    int m = (nl + nr) >> 1;
    int res = bs(ql, qr, x, lch, nl, m);
    if (res != -1) {
      return res;
    }
    return bs(ql, qr, x, rch, m + 1, nr);
  }
};
// :D
void solve() {
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  uniform_int_distribution<> dis(0, 1e9); 
  int N, Q;
  cin >> N >> Q;
  vector<int> arr(N);
  for (int i = 0; i < N; ++i) {
    cin >> arr[i];
  }
  auto f = [&](int a) {
    vector<vector<int>> mtx = {{0, 1}, {1, 1}};
    auto exp = power(mtx, a);
    vector<vector<int>> start = {{1}, {1}};
    vector<vector<int>> last = exp * start;
    return last[0][0];
  };
  // vector<int> gcds(N);
  // for (int i = 0; i <= 11; ++i) {
  //   cout << f(f(i)) << ' ';
  //   gcds.emplace_back(f(i));
  // }
  // for (int i = 0; i < (1 << 11); ++i) {
  //   int g = 0;
  //   for (int j = 0; j < 11; ++j) {
  //     if ((1 << j) & i) {
  //       g = __gcd(g, gcds[j]);
  //     }
  //   }
  //   cout << g << ' ';
  // }
  while (Q--) {
    int qt;
    cin >> qt;
    if (qt == 1) {
      int i, p;
      cin >> i >> p;
      arr[i - 1] = p;
      continue;
    }
    int l, r;
    cin >> l >> r >> MOD;
    --l, --r;
    int g = 0;
    vector<int> nums;
    for (int j = 0; j < 30; ++j) {
      int a = dis(rng) % (r - l + 1);
      int b = dis(rng) % (r - l + 1);
      int x = f(f(arr[l + a] - 1) - 1);
      int y = f(f(arr[l + b] - 1) - 1);
      g = __gcd(g, abs(x - y));
    }
    // g = __gcd(g, x);
    cout << 1 << '\n';
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