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
    st[k] = __gcd(st[2*k], st[2*k+1]);
    k >>= 1;
  }
}

int qry(int a, int b){
  a += N, b += N;
  int ans = st[a];
  while(a <= b){
    if (a&1) ans = __gcd(ans, st[a++]);
    if (~b&1) ans = __gcd(ans, st[b--]);
    a >>= 1, b >>= 1;
  }
  return ans;
}

void solve() {
  cin >> N >> Q;
  vector<int> arr(N);
  --N;
  st.resize(2 * N);
  for (int& x : arr) cin >> x;
  for (int i = 1; i <= N; ++i) {
    upd(i - 1, abs(arr[i] - arr[i - 1]));
  }
  vector<int> prev(N + 1);
  for (int i = 1; i <= N; ++i) {
    if (arr[i] == arr[i - 1]) {
      prev[i] = prev[i - 1];
    } else {
      prev[i] = i;
    }
  }
  while (Q--) {
    int l, r;
    cin >> l >> r;
    --l, --r;
    if (prev[l] == prev[r]) {
      cout << 0 << ' ';
      continue;
    }
    int x = qry(l, r - 1);
    cout << x << ' ';
  }
  cout << '\n';
}

signed main () {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}