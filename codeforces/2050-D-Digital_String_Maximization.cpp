#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  string S;
  cin >> S;
  int N = S.size();
  vector<int> arr(N);
  for (int i = 0; i < N; ++i) {
    arr[i] = S[i] - '0';
  }
  for (int i = 1; i < N; ++i) {
    int j = i - 1;
    while (i && arr[i] > arr[j] + 1) {
      swap(arr[i], arr[j]);
      --i;
      --arr[i];
      j = i - 1;
    }

  } 
  for (int& x : arr) cout << x;
  cout << '\n';
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