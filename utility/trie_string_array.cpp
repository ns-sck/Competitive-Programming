#include <bits/stdc++.h>
using namespace std;

constexpr int MAX = 1e6 + 100;
int nxt[MAX][26];
int cnt[MAX][26];

struct trie {
  int ptr;
  trie() : ptr(0) {}
  void insert(string& s) {
    int p = 0;
    for (int i = 0; i < s.size(); ++i) {
      int c = s[i] - 'a';
      if (!nxt[p][c]) {
        nxt[p][c] = ++ptr;
      }
      ++cnt[p][c];
      p = nxt[p][c];
    }
  }

  int calc(string& s) {
    int64_t ans = 0;
    int p = 0;
    for (int i = 0; i < s.size(); ++i) {
      int c = s[i] - 'a';
      if (!nxt[p][c]) {
        break;
      }
      ans += cnt[p][c];
      p = nxt[p][c];
    }
    return ans * 2;
  }
  // 00000000
  // 00010000
  // 00101010
  // 00101110
  // 10010101
  // 01101010
  int N;
  int val[12321];
  int f(int i, int mask) {
     int ans = 0;
    for (int j = 0; j < N; ++j) {
      if ((mask >> j) & 1) {
        continue;
      }
      ans = val[j] + max(ans, f(i + 1, mask | (1 << j)));
    }
    return ans;
  }
};

void solve() {
  int N;
  cin >> N;
  vector<string> arr(N);
  trie t;
  int64_t len = 0;
  for (string& s : arr) {
    cin >> s;
    len += s.size();
    t.insert(s);
  }
  int64_t ans = 0;
  for (string& s : arr) {
    ans += s.size() * N + len;
    reverse(s.begin(), s.end());
    ans -= t.calc(s);
  }
  cout << ans << '\n';
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