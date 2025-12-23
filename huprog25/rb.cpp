#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

// #define int int64_t

// 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 14, 15, 16, 18, 20, 21, 24, 25, 27, 28, 30, 32, 35, 36, 40, 42

// _ _ _ _ _ _
// 2 2 3 3
// 4 3 3
// 2 2 9

int fp(int a, int b, int MOD) {
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

int inv(int a, int MOD) {
  return fp(a, MOD - 2, MOD);
}

int comb(int a, int b, int MOD) {
  int res = 1;
  for (int i = a; i > a - b; --i) {
    res = (res * i) % MOD;
    res = (res * inv(i - b + 1, MOD));
  }
  return res;
}

int countNumbers(int n, int k) {
  const int MOD = 1e9 + 7;
  auto f = [&](vector<int>& divs) {
    // 2 2 2 3
    if (divs.size() > n) {
      return 0;
    }
    vector<int> a(10);
    for (int i = 0; i < divs.size(); ++i) {
      a[divs[i]]++;
    }   
    vector<int> cnt;  
    for (int i = 0; i < 10; ++i) {
      if (a[i]) {
        cnt.push_back(a[i]);
      }
    }
    int ans = 0;
    for (int i = 0; i < cnt.size(); ++i) {
      int aa = 1;
      auto ncnt = cnt;
      ncnt[i]--;
      int x = n - 1;
      for (int j = 0; j < cnt.size(); ++j) {
        aa = (aa * comb(x, ncnt[j], MOD)) % MOD;
        x -= ncnt[j];
      }
      aa = aa * fp(10, x, MOD) % MOD;
      ans = (ans + aa) % MOD;
    }
    if (n == divs.size()) {
      return ans;
    }
    int bb = 9 - cnt.size();
    int x = n - 1;
    for (int i = 0; i < cnt.size(); ++i) {
      bb = (bb * comb(x, cnt[i], MOD)) % MOD;
      x -= cnt[i];
    }
    bb = bb * fp(10, x, MOD) % MOD;
    ans = (ans + bb) % MOD;
    return ans;
  };
  set<vector<int>> combs;
  auto gen = [&](auto&& self, int t, vector<int> divs) -> void {
    if (t == 1) {
      sort(divs.begin(), divs.end());
      combs.insert(divs);
      return;
    }
    for (int i = 2; i <= 9; ++i) {
      if (t % i == 0) {
        divs.push_back(i);
        self(self, t / i, divs);
        divs.pop_back();
      } 
    }
  };
  // 2 2 2
  // 2 4
  // 8
  gen(gen, k, {});
  set<vector<int>> combss;
  auto gen2 = [&](auto&& self, int i, vector<int> cur) -> void {
    if (i == cur.size()) {
      sort(cur.begin(), cur.end());
      combss.insert(cur);
      return;
    }
    for (int k = 1; k <= 4; ++k) {
      auto curr = cur;
      if (curr[i] * k > 9) break;
      curr[i] *= k;
      self(self, i + 1, curr);
    }
  };
  for (auto v : combs) {
    gen2(gen2, 0, v);
  }
  vector<vector<int>> cmbs;
  for (auto v : combss) {
    cmbs.push_back(v);
  }
  int y = cmbs.size();
  // 2 2 3 6
  // 2 4 
  long long ans = 0;
  for (int i = 1; i < (1 << y); ++i) {
    map<int, int> mp;
    for (int j = 0; j < y; ++j) {
      if ((i >> j) & 1) {
        vector<int> a(10);
        for (int k = 0; k < cmbs[j].size(); ++k) {
          int xx = cmbs[j][k];
          a[xx]++;
          mp[xx] = max(mp[xx], a[xx]);
        }   
      }
    }
    vector<int> div;
    for (auto [cc, dd] : mp) {
      for (int i = 0; i < dd; ++i) {
        div.push_back(cc);
      }
    }
    if (__builtin_popcount(i) & 1) {
      ans = (ans + f(div));
    } else {
      ans = (ans + MOD - f(div)) % MOD;
    }
  }
  return ans;
}

void solve() {
  int N, K;
  cin >> N >> K;
  cout << countNumbers(N, K) << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}