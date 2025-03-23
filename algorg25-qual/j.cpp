#include <bits/stdc++.h>
using namespace std;

#define int long long

constexpr int MOD = 1e9 + 7;
constexpr int MAX = 2e5 + 20;

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
  int N;
  string S;
  cin >> N >> S;
  Hasher str(S);
  reverse(S.begin(), S.end());
  Hasher rev(S);
  reverse(S.begin(), S.end());
  vector<int> two, three;
  for (int i = 0; i < N - 1; ++i) {
    if (S[i] == S[i + 1]) {
      two.emplace_back(i);
    } 
    if (i < N - 2) {
      if (S[i] == S[i + 2]) {
        three.emplace_back(i);
      }
    }
  }
  int total = 0;
  for (int i = 0; i < N - 1; ++i) {
    if (S[i] == S[i + 1]) {
      int len = min(i + 1, N - i - 1);
      int lo = 1, hi = len;
      int ans = 0;
      while (lo <= hi) {
        int mi = (lo + hi) >> 1;
        int left = i - mi + 1, right = i + mi;
        int revleft = N - right - 1, revright = N - left - 1;
        if (str.get(left, right) == rev.get(revleft, revright)) {
          ans = max(ans, mi);
          lo = mi + 1;
        } else {
          hi = mi - 1;
        }
      }
      lo = 1, hi = ans;
      int ans2 = 0;
      while (lo <= hi) {
        int mi = (lo + hi) >> 1;
        int start = i - mi + 1;
        int end = i + mi;
        auto it = lower_bound(two.begin(), two.end(), start);
        bool b = 0;
        if (it != two.end() && *it <= end - 1 && *it != i) b = 1;
        auto it2 = lower_bound(three.begin(), three.end(), start);
        if (it2 != three.end() && *it2 <= end - 2) b = 1;
        if (b) {
          hi = mi - 1;
          ans2 = mi;
        } else {
          lo = mi + 1;
        }
      }
      if (ans && ans2) {
        int x = ans - ans2 + 1;
        total += max(0ll, x);
      }
    }
    if (i < N - 2 && S[i] == S[i + 2]) {
      int len = min(i + 1, N - i - 2);
      int lo = 0, hi = len;
      int ans = 0;
      while (lo <= hi) {
        int mi = (lo + hi) >> 1;
        int left = i - mi + 1, right = i + mi + 1;  
        int revleft = N - right - 1, revright = N - left - 1;
        if (str.get(left, right) == rev.get(revleft, revright)) {
          ans = max(ans, mi);
          lo = mi + 1;
        } else {
          hi = mi - 1;
        }
      }
      lo = 1, hi = ans;
      int ans2 = 0;
      while (lo <= hi) {
        int mi = (lo + hi) >> 1;
        int start = i - mi + 1;
        int end = i + mi + 1;
        auto it = lower_bound(two.begin(), two.end(), start);
        bool b = 0;
        if (it != two.end() && *it <= end - 1) b = 1;
        auto it2 = lower_bound(three.begin(), three.end(), start);
        if (it2 != three.end() && *it2 <= end - 2 && *it2 != i) b = 1;
        if (b) {
          hi = mi - 1;
          ans2 = mi;
        } else {
          lo = mi + 1;
        }
      }
      if (ans && ans2) {
        int x = ans - ans2 + 1;
        total += max(0ll, x);
      }
    }
  }
  cout << total << '\n';
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