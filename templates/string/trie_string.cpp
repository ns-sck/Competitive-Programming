#include <bits/stdc++.h>
using namespace std;

#define int int64_t

struct node {
  node* nxt[26];
  char val;
  bool end = 0;
};
 
struct trie {
  node* root;
  trie() { root = new node(); }

  void insert(string s) {
    node* p = root;   
    for (int i = 0; i < s.size(); ++i) {
      int c = s[i] - 'a';
      if (!p->nxt[c]) p->nxt[c] = new node();
      p = p->nxt[c];
      if (i == s.size() - 1) {
        p->end = 1; 
      }
    }
  }

  void calc(string s) {
    node* p = root;
    for (int i = 0; i < s.size(); ++i) {
      char c = s[i] - 'a';
      p = p->nxt[c];
      if (!p) break;
      if (p->end) {
        
      }
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