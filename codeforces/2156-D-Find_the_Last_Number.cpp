#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t

void solve() {
  int N;
  cin >> N;
  int a = 0;
  auto ask = [&](int i, int x) {
    cout << "? " << i << ' ' << x << '\n';
    cout.flush();
    int resp;
    cin >> resp;
    a++;
    return resp;
  };
  vector<int> idx(N - 1);
  vector<int> nums(N);
  iota(idx.begin(), idx.end(), 1);
  iota(nums.begin(), nums.end(), 1);
  int l = 63 - __builtin_clzll(N);
  int ans = 0;
  int need = (N / 2) + (N & 1);
  for (int i = 0; i <= l; ++i) {
    vector<int> one, zero;
    for (int k = 0; k < idx.size(); ++k) {
      int j = idx[k];
      int resp = ask(j, 1 << i);
      if (resp) {
        one.push_back(j);        
      } else {
        zero.push_back(j);
      }
    }
    vector<int> tmp;
    if (one.size() == need) {
      for (int& j : nums) {
        if (((j >> i) & 1) == 0) {
          tmp.push_back(j);
        }
      }
      idx = zero;
    } else {
      for (int& j : nums) {
        if ((j >> i) & 1) {
          tmp.push_back(j);
        }
      }
      ans |= 1 << i;
      idx = one;
    }
    nums = tmp;
    if (i < l) {
      need = 0;
      for (int& j : nums) {
        if ((j >> (i + 1)) & 1) {
          need++;
        }
      }
    }
  }
  cout << "! " << ans << '\n'; 
  cout.flush();
  // cout << a << '\n';
}

// 5 7 4 2 1 3 8 6

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}