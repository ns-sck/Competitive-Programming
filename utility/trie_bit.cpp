#include <bits/stdc++.h>
using namespace std;

#define int int64_t

struct node {
  node* nxt[2];
  int val;
  int cnt;
  node() : val(0), cnt(0) {
    for (int i : {0, 1}) {
      nxt[i] = nullptr;
    }
  }
};
 
struct trie {
  node* root;
  int bit;
  trie() : bit(30) { root = new node(); }

  void insert(int val) {
    node* p = root;   
    for (int i = bit; ~i; --i) {
      int y = (val >> i) & 1;
      if (!p->nxt[y]) p->nxt[y] = new node();
      ++p->nxt[y]->cnt;
      p = p->nxt[y];
    }
  }

  void remove(int val) {
    node* p = root;
    vector<node*> st;
    for (int i = bit; ~i; --i) {
      int y = (val >> i) & 1;
      node* ch = p->nxt[y];
      assert(ch);
      if (ch->cnt == 1) {
        st.emplace_back(ch);
        p->nxt[y] = nullptr;
      } else {
        --ch->cnt;
      }
      p = ch;
    }
    for (int i = st.size() - 1; ~i; --i) {
      delete st[i];
    }
  }

  int calc(int val) {
    node* p = root;   
    int ans = 0;
    for (int i = bit; ~i; --i) {
      int y = (val >> i) & 1;
      if (!p->nxt[y]) {
        p = p->nxt[y ^ 1];
        ans += 1 << i;
      } else {
        p = p->nxt[y];
      }
    }
    return ans;
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