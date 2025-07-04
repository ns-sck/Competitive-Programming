// https://codeforces.com/contest/1902/problem/E

#include <bits/stdc++.h>
using namespace std;

constexpr int MAX = 1e6 + 100;
int nxt[MAX][26];
int cnt[MAX];

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
      p = nxt[p][c];
      ++cnt[p];
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
      p = nxt[p][c];
      ans += cnt[p];
    }
    return ans * 2;
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