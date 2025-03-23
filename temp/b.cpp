#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int N;
  cin >> N;
  vector<int> arr(N);
  bool all = 1, exist = 0;
  for (int& x : arr) {
    cin >> x;
    all &= x == 0;
    exist |= x == 0;
  }
  if (!exist) {
    cout << 1 << '\n' << 1 << ' ' << N << '\n';
    return;
  }
  if (all) {
    cout << 3 << '\n';
    cout << N - 1 << ' ' << N << '\n';
    cout << 1 << ' ' << N - 2 << '\n';
    cout << 1 << ' ' << 2 << '\n';
    return;
  }
  int idx = 0;
  for (int i = 1; i < N; ++i) {
    if (arr[i] != 0) {
      idx = i;
      break;
    }
  }
  if (idx == 0) {
    cout << 2 << '\n';
    cout << 2 << ' ' << N << '\n';
    cout << 1 << ' ' << 2 << '\n';
  } else if (idx == N - 1) {
    cout << 2 << '\n';
    cout << 1 << ' ' << N - 1 << '\n';
    cout << 1 << ' ' << 2 << '\n';
  } else {
    bool a = 0, b = 0;
    for (int i = 0; i < idx; ++i) {
      if (arr[i] == 0) {
        a = 1;
        break;
      }
    }
    for (int i = idx + 1; i < N; ++i) {
      if (arr[i] == 0) {
        b = 1;
        break;
      }
    }
    if (a && b) {
      cout << 3 << '\n';
      if (idx == 1) {
        cout << 3 << ' ' << N << '\n';
        cout << 1 << ' ' << 2 << '\n';
        cout << 1 << ' ' << 2 << '\n';
      } else {
        cout << idx + 1 << ' ' << N << '\n';
        cout << 1 << ' ' << idx << '\n';
        cout << 1 << ' ' << 2 << '\n';
      }
    } else if (a && !b) {
      cout << 2 << '\n';
      cout << 1 << ' ' << idx + 1 << '\n';
      cout << 1 << ' ' << N - idx << '\n';
    } else if (!a && b) {
      cout << 2 << '\n';
      cout << idx + 1 << ' ' << N << '\n';
      cout << 1 << ' ' << idx + 1 << '\n';
    }
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