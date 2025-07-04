  #include <bits/stdc++.h>
  using namespace std;

  #define int int64_t

  constexpr int MOD = 1e9 + 7;
  constexpr int MAX = 1e7 + 1;

  int prfx[MAX], fct[MAX];

  vector<int> spf(MAX);
  vector<int> prs;

  void sieve() {
    for (int i = 2; i < MAX; ++i) {
      if (spf[i]) {
        continue;
      }
      spf[i] = i;
      prs.emplace_back(i);
      for (int j = i * i; j < MAX; j += i) {
        if (!spf[j]) {
          spf[j] = i;
        }
      }
    }
  }

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

  void init() {
    sieve();
    prfx[0] = 1, fct[0] = 1;
    for (int i = 1; i < MAX; ++i) {
      fct[i] = fct[i - 1] * i % MOD;
      prfx[i] = prfx[i - 1] * fct[i] % MOD;
    }
  }

  void solve() {
    int L, R, K;
    cin >> L >> R >> K;
    int x = K, mx = 1;
    while (x > 1) {
      int y = spf[x];
      while (x % y == 0) x /= y;
      mx = max(mx, y);
    }
    int ans = prfx[R] * fp(prfx[L - 1], MOD - 2) % MOD;
    int exp = mx, zero = 0;
    while (1) {
      int l = (L - 1) / exp + 1, r = R / exp;
      if (l * exp < L || r * exp > R) break;
      int sub = (((r + 1) * exp - 1) - R) * r - (l * exp - L) * (l - 1);
      zero += (r * (r + 1) / 2 - l * (l - 1) / 2) * exp - sub;
      exp *= mx;
    }
    ans = ans * fp(fp(K, zero), MOD - 2) % MOD;
    cout << ans << '\n';
  }

  signed main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int t = 1;
    cin >> t;
    while (t--) {
      solve();
    }
    return 0;
  }