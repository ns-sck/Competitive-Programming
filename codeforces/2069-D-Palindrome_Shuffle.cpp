#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  string S;
  cin >> S;
  int i = 0, j = S.size() - 1;
  while (S[i] == S[j]) {
    i++, j--;
  }
  vector<int> arr;
  for (; i <= j; ++i) {
    arr.push_back(S[i] - 'a');
  }
  int n = arr.size();
  if (n == 0) {
    cout << 0 << '\n';
    return;
  }
  auto f = [&]() {
    int l = n / 2 - 1, r = l + 1;
    while (arr[l] == arr[r]) {
      l--, r++;
    }
    vector<int> left(26), right(26);
    for (int i = 0; i < n / 2; ++i) {
      left[arr[i]]++;
    }
    for (int i = n / 2; i < n; ++i) {
      right[arr[i]]++;
    }
    bool ok = 1;
    for (int i = 0; i < 26; ++i) {
      ok &= left[i] == right[i];
    }
    if (ok) {
      return l + 1;
    }
    for (int i = n / 2; i < n; ++i) {
      int x = arr[i];
      if (right[x] <= left[x]) {
        continue;
      }
      left[x]++;
      right[x]--;
      for (int j = 0; j < 26; ++j) {
        if (left[j] > right[j]) {
          left[j]--;
          right[j]++;
        }
      }
      bool prf = 1;
      for (int j = 0; j < 26; ++j) {
        prf &= left[j] == right[j];
      }
      if (prf) {
        return i + 1; 
      }
    }
  };
  int ans1 = f();
  reverse(arr.begin(), arr.end());
  int ans2 = f();
  cout << min(ans1, ans2) << '\n';
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