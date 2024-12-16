#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define lch 2 * i
#define rch 2 * i + 1

constexpr int INF = 1ll << 61;
int N, Q;

struct node {
  int lazy = INF;
  int sum;
  // int mn;
  // int mx;
} st[1 << 19];

void print_st() {
  int str = 1;
  int lc = 1;
  for (int lv = 0; lv < 5; lv++) {
    for (int i = str; i < str + lc; i++) {
      cout << st[i].sum << ' ';
    }
    cout << '\n';
    str += lc;
    lc *= 2;
  }
}

void push(int i, int nl, int nr) 
{   
  if (st[i].lazy == INF) return;

  st[i].sum = (st[i].lazy * (nr - nl + 1));
  // st[i].mn = st[i].lazy;
  // st[i].mx = st[i].lazy;

  if (nl ^ nr) {
    st[lch].lazy = st[i].lazy;
    st[rch].lazy = st[i].lazy;
  }
  st[i].lazy = INF;
}

void upd(int ql, int qr, int val, int i = 1, int nl = 0, int nr = N - 1) 
{
  push(i, nl, nr);
  if (nl > qr || nr < ql) return;

  if (nl >= ql && nr <= qr) {
    st[i].lazy = val;
    push(i, nl, nr);
    return;
  }

  int mid = (nl + nr) / 2;
  upd(ql, qr, val, lch, nl, mid);
  upd(ql, qr, val, rch, mid+1, nr);

  st[i].sum = st[lch].sum + st[rch].sum;
  // st[i].mn = min(st[lch].mn, st[rch].mn);
  // st[i].mx = max(st[lch].mx, st[rch].mx);
}

int query(int ql, int qr, int i = 1, int nl = 0, int nr = N - 1) 
{
  push(i, nl, nr);
  if (nl > qr || nr < ql) return 0;
  // if (nl > qr || nr < ql) return INF;
  // if (nl > qr || nr < ql) return -INF;

  if (nl >= ql && nr <= qr) return st[i].sum;
  // if (nl >= ql && nr <= qr) return st[i].mn;
  // if (nl >= ql && nr <= qr) return st[i].mx;

  int mid = (nl + nr) / 2;
  int t1 = query(ql, qr, lch, nl, mid);
  int t2 = query(ql, qr, rch, mid + 1, nr);

  return t1 + t2;
  // return min(t1, t2);
  // return max(t1, t2);
}

// int bs(int x, int i = 1, int nl = 0, int nr = N - 1) {

//   if (nl == nr)
//     return nl;

//   int m = (nl + nr) / 2;

//   push(i, nl, nr);
//   if (st[lch].mx >= x)
//     return bs(x, lch, nl, m);

//   return bs(x, rch, m + 1, nr);
// }

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