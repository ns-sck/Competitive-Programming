#include <bits/stdc++.h>
using namespace std;

#define int int64_t

constexpr int MAX = 1e6 + 1;

vector<int> spf(MAX);
vector<int> prs;

void sieve() {
  for (int i = 2; i < MAX; ++i) {
    if (spf[i]) {
      continue;
    }
    spf[i] = i;
    prs.emplace_back(i);
    for (int j = i * i; j < MAX; j += i) {
      if (!spf[j]) {
        spf[j] = i;
      }
    }
  }
}

void solve() {
  sieve();
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  ofstream o("edge.txt");
  while (prs.size() < 200000) {
    int x = (rng() % MAX);
    if (x == 0) x = 1;
    prs.emplace_back(x);
  }
  shuffle(prs.begin(), prs.end(), rng);
  o << 200000 << ' ' << 2 << '\n';
  for (auto& x : prs) o << x << ' ';
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