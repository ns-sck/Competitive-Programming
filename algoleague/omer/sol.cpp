#include <bits/stdc++.h>
using namespace std;

#define int int64_t

int MOD = 1e9 + 7;
constexpr int MAX = 1e5 + 1;

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
  mt19937 rng(chrono::high_resolution_clock().now().time_since_epoch().count());
  static const int _n = 3;
  static const array<int, _n> p = {1171, 1453, 1973};
  static int pw[_n][MAX], inv[_n][MAX];
  static int alp[26];

  static bool init = []() {
    iota(alp, alp + 26, 1);
    shuffle(alp, alp + 26, rng);
    for (int i = 0; i < _n; ++i) {
      pw[i][0] = 1, inv[i][0] = 1;
      for (int j = 1; j < MAX; ++j) {
        pw[i][j] = pw[i][j - 1] * p[i] % MOD;
        inv[i][j] = fp(pw[i][j], MOD - 2);
      }
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
  int S, P;
  string str;
  cin >> S >> MOD >> P >> str;
  Hasher hsh(str);
  int ans = 0;
  int lo = 1, hi = S / 2;
  while (lo <= hi) {
    int mi = (lo + hi) >> 1;
    map<int, int> seen;
    for (int i = 0; i < S - mi + 1; ++i) {
      int x = hsh.get(i, i + mi - 1).h[0];
      if (seen.count(x) && seen[x] + mi - 2 < i) {
        ans = max(ans, mi);
        break;
      }
      if (!seen.count(x)) {
        seen[x] = i + 1;
      }
    }
    if (ans >= mi) {
      lo = mi + 1;
    } else {
      hi = mi - 1;
    }
  }
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