#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void merge(vector<int>& arr, int l, int m, int r) {
  vector<int> v;
  auto ask = [&](int i, int j) {
    cout << "? " << i << ' ' << j << '\n' << flush;
    string s;
    cin >> s;
    return s == "YES";
  };
  int i = l, j = m + 1;
  while (i <= m && j <= r) {
    if (ask(arr[i], arr[j])) {
      v.push_back(arr[i++]);
    } else {
      v.push_back(arr[j++]);
    }
  }
  while (i <= m) {
    v.push_back(arr[i++]);
  }
  while (j <= r) {
    v.push_back(arr[j++]);
  }
  for (i = l; i <= r; ++i) {
    arr[i] = v[i - l];
  }
}

void srt(vector<int>& arr, int l, int r) {
  if (r <= l) return;
  int m = (r + l) / 2;
  srt(arr, l, m);
  srt(arr, m + 1, r);
  merge(arr, l, m, r);
}

void solve() {
  int N;
  cin >> N;
  vector<int> arr(N);
  iota(arr.begin(), arr.end(), 1);
  srt(arr, 0, N - 1);
  vector<int> ans(N);
  for (int i = 0; i < N; ++i) {
    ans[arr[i] - 1] = i + 1;
  }
  cout << "! ";
  for (int& x : ans) {
    cout << x << " \n"[x == ans.back()];
  } 
  cout.flush();
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