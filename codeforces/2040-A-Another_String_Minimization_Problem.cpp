#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int N, M;
  cin >> N >> M;
  string S;
  for (int i = 0; i < M; ++i) {
    S += 'B';
  }
  for (int i = 0; i < N; ++i) {
    int x; cin >> x;
    if (x > M / 2) {
      x = M - x + 1;
    }
    if (S[x - 1] == 'A') {
      S[M - x] = 'A';
    } else {
      S[x - 1] = 'A';
    }
  }
  cout << S << '\n';
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