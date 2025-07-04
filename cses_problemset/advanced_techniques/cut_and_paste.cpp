#include <bits/stdc++.h>
using namespace std;

#define int int64_t

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<int> dis(1, (int) 2e9);

struct item {
  int key, prior, size;
  item *l, *r;
  item() {}
  item(int key) : key(key), prior(dis(rng)), l(nullptr), r(nullptr), size(1) {}
  item(int key, int prior) : key(key), prior(prior), l(nullptr), r(nullptr), size(1) {}
};
typedef item *pitem;

int size(pitem t) {
  if (t == nullptr) return 0;
  return t->size;
}

void split(pitem t, int pos, pitem &l, pitem &r) {
  if (!t) {
    l = r = nullptr;
  } else {
    int curr_pos = size(t->l);
    if (pos <= curr_pos) {
      split(t->l, pos, l, t->l), r = t;
    } else {
      split(t->r, pos - curr_pos - 1, t->r, r), l = t;
    }
    t->size = size(t->l) + size(t->r) + 1;
  }
}

void insert(pitem &t, pitem it, int pos) {
  if (!t) {
    t = it;
  } else if (it->prior > t->prior) {
    split(t, pos, it->l, it->r), t = it;
  } else {
    int curr_pos = size(t->l);
    if (pos <= curr_pos) {
      insert(t->l, it, pos);
    } else {
      insert(t->r, it, pos - curr_pos - 1);
    }
  }
  t->size = size(t->l) + size(t->r) + 1;
}

void merge(pitem &t, pitem l, pitem r) {
  if (!l || !r) {
    t = l ? l : r;
  } else if (l->prior > r->prior) {
    merge(l->r, l->r, r), t = l;
  } else {
    merge(r->l, l, r->l), t = r;
  }
  if (t) t->size = size(t->l) + size(t->r) + 1;
}

void erase(pitem &t, int key) {
  if (t->key == key) {
    pitem th = t;
    merge(t, t->l, t->r);
    delete th;
  }
  else {
    erase(key < t->key ? t->l : t->r, key);
  }
}

pitem unite(pitem l, pitem r) {
  if (!l || !r) {
    return l ? l : r;
  } 
  if (l->prior < r->prior) {
    swap(l, r);
  }
  pitem lt, rt;
  split(r, l->key, lt, rt);
  l->l = unite(l->l, lt);
  l->r = unite(l->r, rt);
  return l;
}

void print(pitem t) {
  if (t == nullptr) return;
  print(t->l);
  char c = 'a' + t->key;
  cout << c;
  print(t->r);
}

void solve() {
  int N, Q;
  string S;
  cin >> N >> Q >> S;
  pitem trp = nullptr;
  for (int i = 0; i < N; ++i) {
    insert(trp, new item(S[i] - 'a'), i);
  }
  while (Q--) {
    int l, r;
    cin >> l >> r;
    --l, --r;
    pitem a, b, c, d;
    split(trp, l, a, b);
    split(b, r - l + 1, c, d);
    merge(trp, a, d);
    merge(trp, trp, c);
  }
  print(trp);
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