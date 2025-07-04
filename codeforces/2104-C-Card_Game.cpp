#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int N;
  string S;
  cin >> N >> S;
  int last = -1;
  int a = count(S.begin(), S.end(), 'A');
  int b = count(S.begin(), S.end(), 'B');
  if (S[0] == 'B' && S[N - 1] == 'B') {
    cout << "Bob\n";
  } else if (S[0] == S[N - 1]) {
    cout << "Alice\n";
  } else if (S[N - 1] == 'B') {
    if (b == 1) cout << "Alice\n";
    else cout << "Bob\n";
  } else {
    if (S[N - 2] == 'A') cout << "Alice\n";
    else cout << "Bob\n";
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