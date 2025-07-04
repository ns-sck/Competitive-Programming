#include <bits/stdc++.h>
using namespace std;

#define int int64_t
constexpr int MOD = 998244353;

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

void solve() {
  int N;
  cin >> N;
  vector<int> arr(N + 1);
  vector<int> ones;
  for (int i = 1; i <= N; ++i) {
    cin >> arr[i];
    if (arr[i] == 1) {
      ones.emplace_back(i);
    }
  }
  map<int, int> pos, neg;
  vector<int> cnt(N + 1);
  neg[0] = 1;
  for (int i = 1; i <= N; ++i) {
    map<int, int> temp_pos, temp_neg;
    if (arr[i] == 1) {
      for (auto& [x, y] : pos) {
        if (arr[i] * (x - 1) <= 3000) {
          temp_pos[arr[i] * (x - 1)] += y;
        }
      }
      for (auto& [x, y] : neg) {
        if (x == 0) {
          temp_pos[1] += y;
        } else if (arr[i] * (x + 1) <= 3000) {
          temp_neg[arr[i] * (x + 1)] += y;
        }
      }
      cnt[i] = pos[2] + neg[0];
    } else if (arr[i] > 0) {
      for (auto& [x, y] : pos) {
        if (arr[i] * (x - 1) <= 3000) {
          temp_pos[arr[i] * (x - 1)] += y;
        }
      }
      for (auto& [x, y] : neg) {
        if (x == 0) {
          temp_pos[arr[i]] += y;
        } else if (arr[i] * (x + 1) <= 3000) {
          temp_neg[arr[i] * (x + 1)] += y;
        }
      }
    } else if (arr[i] < 0) {
      for (auto& [x, y] : neg) {
        if (x == 0) {
          temp_neg[-arr[i]] += y;
        } else if (-arr[i] * (x + 1) <= 3000) {
          temp_pos[-arr[i] * (x + 1)] += y;
        }
      }
      for (auto& [x, y] : pos) {
        if (-arr[i] * (x - 1) <= 3000) {
          temp_neg[-arr[i] * (x - 1)] += y;
        }
      }
    }
    for (auto& [x, y] : temp_pos) {
      if (x <= 0) continue;
      pos[x] = (pos[x] + y) % MOD;
    }
    for (auto& [x, y] : temp_neg) {
      if (x > 0) continue;
      neg[x] = (neg[x] + y) % MOD;
    }
  }  
  auto add = [&](int a, int b, int c) {
    int x = (a + b * c);
    if (x < 0) {
      x += 5e18;
    }
    return x % MOD;
  };
  vector<int> dpp(N + 1), dpn(N + 1);
  vector<int> poss(N + 1), negg(N + 1);
  for (int i = 1; i <= N; ++i) {
    if (arr[i] == 0) continue;
    if (arr[i] > 0) {
      dpp[i] = arr[i];
      poss[i] = 1;
    } else {
      dpn[i] = arr[i];
      negg[i] = 1;
    }
    for (int j = 1; j < i; ++j) {
      if (arr[j] == 0) continue;
      if (arr[i] > 0) {
        int a = (dpp[j] - poss[j] - cnt[j]) % MOD;
        dpp[i] = (dpp[i] + a * arr[i]);
        poss[i] += poss[j];
      } else {

      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= N; ++i) {
    ans += dpp[i];
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