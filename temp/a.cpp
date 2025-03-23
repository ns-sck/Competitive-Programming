#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int N, K;
  cin >> N >> K;
  string S;
  cin >> S;
  int i = 0, j = N - 1;
  while (i < j && K) {
    if (S[i] > S[j]) {
      swap(S[i], S[j]);
      --K;
    } 
    i++, j--;
  }
  string s = S;
  bool ok = 0;
  for (int i = 0; i < N - 1; ++i) {
    ok |= S[i] != S[i + 1];
  }
  reverse(s.begin(), s.end());
  if (S == s && K && ok) {
    cout << "YES\n";
    return;
  }
  if (S < s) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
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