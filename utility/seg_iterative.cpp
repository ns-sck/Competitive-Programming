#include <bits/stdc++.h>
using namespace std;

#define int int64_t

#include <bits/stdc++.h>
using namespace std;

#define int int64_t

vector<int> st;
int N, Q;

void upd(int k, int x){
  k += N;
  st[k] = x; 
  k >>= 1;
  while(k >= 1){
    st[k] = max(st[2*k], st[2*k+1]);
    k >>= 1;
  }
}

int qry(int a, int b){
  a += N, b += N;
  int ans = 0;
  while(a <= b){
    if (a & 1) ans = max(ans, st[a++]);
    if (~b & 1) ans = max(ans, st[b--]);
    a >>= 1, b >>= 1;
  }
  return ans;
}

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