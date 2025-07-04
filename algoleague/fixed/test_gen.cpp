#include <bits/stdc++.h>
using namespace std;

#define int int64_t

constexpr int MAX = 5e6 + 1;

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

  int tc = 26;
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  int mn = 1;
  int mx = 5e6 + 1;
  int size[26] = {4, 7, 11, 145, 1932, 5743, 11324, 23485, 39423, 53242, 
                  71321,  89427, 101234, 127436, 139523,  
                  151232, 166289, 173128, 183213, 191311, 200000, 200000, 200000, 200000, 200000, 200000};
  int K[26] = {2, 3, 2, 7, 34, 42, 23, 3, 7, 312, 23, 13, 2, 3242, 7, 93, 4100, 11, 234, 2, 64721, 2, 2, 2532, 2, 5};
  for (int i = 0; i < tc; ++i) {
    int n = size[i];
    int k = K[i];
    string s = "input";
    s += to_string(i);
    s += ".txt";
    ofstream o(s); 
    o << n << ' ' << k << '\n';
    for (int j = 0; j < n; ++j) {
      int a = rng() % 100 + 1;
      int y = rng() % a;
      int x = rng() % (mx - 1) + 1;
      if (i == 23 || i == 20) {
        y = -1;
      } 
      if (y == 1) {
        x = 0;
      }
      o << x << ' ';
      assert(x < mx && x >= 0);
    }
    mn = n;
  }
  int kk[6] = {2, 2, 2, 23232, 3, 2};
  int edge[] = {4849845, 4037880, 4594590, 4408950, 3233230, 4157010, 4555320};
  for (int j = 0; j < 6; ++j) {
    string s = "input";
    s += to_string(tc + j);
    s += ".txt";
    ofstream o(s);
    o << 200000 << ' ' << kk[j] << '\n';
    for (int i = 0; i < 200000; ++i) {
      int b = rng() % 3;
      if (b <= 1) {
        int z = rng() % 3;
        o << edge[z] << ' ';
      } else {
        int x = rng() % (mx - 1) + 1;
        int a = rng() % 50 + 1;
        int y = rng() % a;
        if (y == 1 && (j & 1)) x = 0;
        assert(x < mx && x >= 0);
        o << x << ' ';
      }
    }
  }
  sieve();
  ofstream o("input32.txt");
  o << 200000 << ' ' << 2 << '\n';
  sort(prs.rbegin(), prs.rend());
  vector<int> pp;
  int c = 0;
  for (int& p : prs) {
    pp.emplace_back(p);
    if (++c == 200000) break;
  }
  shuffle(pp.begin(), pp.end(), rng);
  for (int& p : pp) {
    o << p << ' ';
  }
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