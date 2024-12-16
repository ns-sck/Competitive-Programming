#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int a, b;
  cin >> a >> b;
  if (a > b) {
    swap(a, b);
  }
  string A = to_string(a), B = to_string(b);
  if (A.size() < B.size()) {
    string s(A.size(), '9');
    cout << s << '\n';
    return;
  }
  if (B[0] - A[0] > 1) {
    char c = A[0] + 1;
    string ans(A.size(), c);
    cout << ans << '\n';
    return;
  }
  vector<int> arr(A.size()), brr(B.size());
  for (int i = 0; i < A.size(); ++i) {
    arr[i] = A[i] - '0';
  }
  for (int i = 0; i < A.size(); ++i) {
    brr[i] = B[i] - '0';
  }
  int diff = 9, ans = a;
  auto dfs = [&](auto&& self, int i, bool b1, bool b2, int lb, int ub, int num) {
    if (i == A.size()) {
      if (ub - lb < diff) {
        diff = ub - lb;
        ans = num;
      }
      return;
    }
    int left = b1 ? arr[i] : 0;
    int right = b2 ? brr[i] : 9;
    bool xd = 0;
    int mnn = 10, ths = arr[i];
    for (int j = left; j <= right; ++j) {
      bool b11 = b1 && (j == arr[i]), b22 = b2 & (j == brr[i]);
      if (!b11 && !b22) {
        int dff = max(abs(lb - j), abs(ub - j));
        if (dff < mnn) {
          mnn = dff;
          ths = j;
        }
      } else {
        self(self, i + 1, b1 && (j == arr[i]), b2 && (j == brr[i]), min(lb, j), max(ub, j), num * 10 + j);
      }
    }
    if (mnn != 10) {
      self(self, i + 1, 0, 0, min(lb, ths), max(ub, ths), num * 10 + ths);
    }
  };
  for (int i = arr[0]; i <= brr[0]; ++i) {
    dfs(dfs, 1, i == arr[0], i == brr[0], i, i, i);
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
