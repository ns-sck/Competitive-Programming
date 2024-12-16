#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int N;
  cin >> N;
  vector<int> arr(N);
  int s = 0;
  for (int& x : arr) cin >> x, s += x;
  if (s % N) {
    cout << "No\n";
    return;
  }
  s /= N;
  for (int i = N - 2; i; --i) {
    while (arr[i + 1] > s) {
      --arr[i + 1];
      ++arr[i - 1];
    }
    while (arr[i + 1] < s) {
      ++arr[i + 1]; 
      --arr[i - 1]; 
    }
  }
  if (arr[0] == s && arr[1] == s) {
    cout << "Yes\n";
  } else cout << "No\n";
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