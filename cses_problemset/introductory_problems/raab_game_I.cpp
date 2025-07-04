#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int N, A, B;
  cin >> N >> A >> B;
  if ((A + B > N) || (A ^ B && (!A || !B))) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  vector<int> a, b;
  for (int i = 0; i < A; ++i) {
    a.push_back(N - i);
    b.push_back(N - i - B);
  }
  for (int i = 0; i < B; ++i) {
    b.push_back(N - i);
    a.push_back(N - i - A);
  }
  for (int i = 0; i < N - A - B; ++i) {
    a.push_back(i + 1);
    b.push_back(i + 1);
  } 
  for (int& x : a) {
    cout << x << " \n"[x == a.back()];
  }
  for (int& x : b) {
    cout << x << " \n"[x == b.back()];
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