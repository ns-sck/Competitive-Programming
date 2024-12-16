#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int N;
  cin >> N;
  vector<int> p, n;
  int mxe = 0, mne = 1ll << 61;
  for (int i = 0; i < N; ++i) {
    int x;
    cin >> x;
    if (x < 0) n.emplace_back(x);
    else p.emplace_back(x);
    mxe = max(mxe, x);
    mne = min(mne, x);
  }
  sort(p.rbegin(), p.rend());
  sort(n.begin(), n.end());
  int i = 0, j = 0;
  p.emplace_back(1ll << 61);
  n.emplace_back(1ll << 61);
  vector<int> arr;
  int sum = 0;
  int mx = 0;
  while (arr.size() < N) {
    int ff = abs(sum + p[i]);
    int ss = abs(sum + n[j]);
    if (ff <= ss) {
      arr.emplace_back(p[i++]);
    } else {
      arr.emplace_back(n[j++]);
    }
    sum += arr.back();
    mx = max(mx, sum);
  } 
  if (mx < mxe - mne) {
    cout << "Yes\n";
    for (auto x : arr) {
      cout << x << ' ';
    }
    cout << '\n';
  } else {
    cout << "No\n";
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