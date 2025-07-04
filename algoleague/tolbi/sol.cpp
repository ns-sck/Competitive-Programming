#include <bits/stdc++.h>
using namespace std;

#define int int64_t

constexpr int MOD = 232323233;
constexpr int MAX = 1e5 + 1;
int x[MAX];

mt19937 rng(chrono::high_resolution_clock().now().time_since_epoch().count());

int fp(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = res * a % MOD;
    }
    a = a * a % MOD;
    b >>= 1;
  }
  return res;
}

namespace Numeric {
  static const int _n = 3;
  static const array<int, _n> p = {1171, 1453, 1973};
  static int pw[_n][MAX], inv[_n][MAX];
  static int alp[26];

  static void fillarr(int* arr, int p) {
    arr[0] = 1;
    for (int i = 1; i < MAX; ++i) {
      arr[i] = arr[i - 1] * p % MOD;
    }
  }
  static void fillinv(int* arr, int* inv) {
    inv[0] = 1;
    for (int i = 1; i < MAX; ++i) {
      inv[i] = fp(arr[i], MOD - 2);
    }
  }

  static bool init = []() {
    iota(alp, alp + 26, 1);
    shuffle(alp, alp + 26, rng);
    fillarr(x, 26);
    for (int i = 0; i < _n; ++i) {
      fillarr(pw[i], p[i]);
      fillinv(pw[i], inv[i]);
    }
    return true;
  }();
};
using namespace Numeric;

struct Hash {
  array<int, _n> h;
  Hash(char& c) {
    for (int i = 0; i < _n; ++i) {
      h[i] = alp[c - 'a'];
    }
  }
  bool operator<(const Hash& other) const { return h < other.h; }
  bool operator>(const Hash& other) const { return h > other.h; }
  bool operator<=(const Hash& other) const { return h <= other.h; }
  bool operator>=(const Hash& other) const { return h >= other.h; }
  bool operator==(const Hash& other) const { return h == other.h; }
  bool operator!=(const Hash& other) const { return h != other.h; }
  void operator+=(Hash& other) { *this = *this + other; }
  void operator-=(Hash& other) { *this = *this - other; }

  Hash operator+(Hash& other) {
    Hash res = *this;
    for (int i = 0; i < _n; ++i) {
      res.h[i] = (res.h[i] + other.h[i]) % MOD;
    }
    return res;
  }

  Hash operator-(Hash& other) {
    Hash res = *this;
    for (int i = 0; i < _n; ++i) {
      res.h[i] = (res.h[i] - other.h[i] + MOD) % MOD;
    }
    return res;
  }

  Hash operator<<(int s) const {
    Hash res = *this;
    for (int i = 0; i < _n; ++i) {
      res.h[i] = (res.h[i] * pw[i][s]) % MOD;
    }
    return res;
  }

  Hash operator>>(int s) const {
    Hash res = *this;
    for (int i = 0; i < _n; ++i) {
      res.h[i] = (res.h[i] * inv[i][s]) % MOD;
    }
    return res;
  }
};

struct Hasher {
  vector<Hash> pref;
  Hasher(string& s) {
    for (int i = 0; i < s.size(); ++i) {
      pref.emplace_back(Hash(s[i]) << i);
      if (i) pref[i] += pref[i - 1];
    }
  } 
  Hash get(int l, int r) {
    Hash res = pref[r];
    if (l) {
      res -= pref[l - 1];
      res = res >> l;
    }
    return res;
  }
};

void solve() {
  int N, M;
  string S;
  cin >> N >> M >> S;
  vector<int> len;
  map<Hash, bool> mp;
  while (M--) {
    string s;
    cin >> s;
    Hasher h(s);
    mp[h.get(0, s.size() - 1)] = 1;
    len.emplace_back(s.size());
  }
  sort(len.begin(), len.end());
  len.erase(unique(len.begin(), len.end()), len.end());
  Hasher hshr(S);
  vector<int> rb(N + 1, -1);
  vector<pair<int, int>> seg, seg2;
  for (int i = N - 1; ~i; --i) {
    for (int& j : len) {
      if (i + j > N) break;
      Hash h = hshr.get(i, i + j - 1);
      if (mp[h]) {
        rb[i] = max({rb[i], i + j - 1, rb[i + j]});
      }
    }
    if (~rb[i]) seg.emplace_back(rb[i], -i);
  }
  int left = N + 10;
  sort(seg.rbegin(), seg.rend());
  for (auto [r, l] : seg) {
    if (left <= -l) continue;
    seg2.emplace_back(-l, r);
    left = -l;
  }
  sort(seg2.begin(), seg2.end());
  int right = -1, ans = 1;
  for (auto [l, r] : seg2) {
    int len = r - l + 1;
    if (right >= l) {
      ans = (ans + x[len]) % MOD;
      len = right - l + 1;
      ans = (ans - x[len] + MOD) % MOD;
    } else {
      ans = (ans + x[len] - 1) % MOD;
    }
    right = r;
  }
  cout << ans << '\n';
}

signed main () {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}