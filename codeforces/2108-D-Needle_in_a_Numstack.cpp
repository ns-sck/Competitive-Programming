#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int N, K;
  cin >> N >> K;
  auto ask = [&](int i) {
    cout << "? " << i << '\n';
    cout.flush();
    int j;
    cin >> j;
    return j;
  };
  vector<int> mda(51), mdb(51);
  for (int i = 0; i < K; ++i) {
    int a = ask(i + 1);
    int b = ask(N - K + i + 1);
    mda[a] = i % K;
    mdb[b] = (N - K + i) % K;
  }
  int d = 51;
  for (int i = 1; i <= K; ++i) {
    if (mda[i] ^ mdb[i]) {
      d = min(mda[i], d);
    }
  }
  if (d == 51) {
    if (N == 2 * K) {
      cout << "! " << K << ' ' << K << '\n';
      cout.flush();
    } else {
      cout << "! -1" << '\n';
      cout.flush();
    }
    return;
  }

  /*
  6 3
  3 3
  1 2 3
  2 1 3
  */
  int lo = 1, hi = (N - d) / K, st = 1;
    while (lo <= hi) {
    int mi = (lo + hi) >> 1;
    int x = ask(mi * K + d + 1);
    if (mda[x] == d) {
      lo = mi + 1;
    } else {
      st = mi * K + d;
      hi = mi - 1;
    }
  }
  int ansl = max(K + 1, st - K + 2), ansr = min(st + 1, N - K + 1);
  for (int i = ansr; i >= ansl; --i) {
    int m = ask(i);
    int l = i - K > 0 ? ask(i - K) : m;
    if (m ^ l) {
      ansr = min(ansr, i);
    }
    if (((i - 1 + K) % K) ^ mdb[m]) {
      ansl = max(ansl, i + 1);
    }
  }
  if (ansl == ansr) {
    cout << "! " << ansl - 1 << ' ' << N - ansl + 1 << '\n';
  } else {
    cout << "! -1\n";
  }
  cout.flush();
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}