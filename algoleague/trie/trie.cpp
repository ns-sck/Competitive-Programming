#include <bits/stdc++.h>
using namespace std;

#define int int64_t
constexpr int MAX = 2e5 + 1;

int nxt[MAX][26];

struct trie {
    // int N;
    int ptr;
    trie() : ptr(0) {}

    void insert(string& s) {
        int ptr = 0;
        for (char& chr : s) {
            int c = chr - 'a';
            if (nxt[ptr][c] == 0) {
                nxt[ptr][c] = ++ptr;
            }
            ptr = nxt[ptr][c];
        }
    }

    void search(string& s) {
        int ptr = 0;
        for (char& chr : s) {
            int c = chr - 'a';
            // assert(ptr->nxt[c]);
            ptr = nxt[ptr][c];
            // other logic
        }
    }
};

void solve() {

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