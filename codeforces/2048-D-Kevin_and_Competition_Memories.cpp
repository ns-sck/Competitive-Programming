#include <bits/stdc++.h>
using namespace std;

#define int int64_t

class BIT {
public:
    int N;
    vector<int> B1, B2;

    BIT(int size) : N(size), B1(size + 1, 0), B2(size + 1, 0) {}

    void add(vector<int>& b, int idx, int x) {
        for (; idx <= N; idx += idx & -idx)
            b[idx] += x;
    }

    void range_add(int l, int r, int x) {
        add(B1, l, x);
        add(B1, r + 1, -x);
        add(B2, l, x * (l - 1));
        add(B2, r + 1, -x * r);
    }

    int sum(const vector<int>& b, int idx) {
        int total = 0;
        for (; idx > 0; idx -= idx & -idx)
            total += b[idx];
        return total;
    }

    int prefix_sum(int idx) {
        return sum(B1, idx) * idx - sum(B2, idx);
    }

    int range_sum(int l, int r) {
        return prefix_sum(r) - prefix_sum(l - 1);
    }
};

vector<int> st;
int n;

void upd(int k, int x){
  k += n;
  st[k] = x; 
  k >>= 1;
  while(k >= 1){
    st[k] = max(st[2*k], st[2*k+1]);
    k >>= 1;
  }
}

int qry(int a, int b){
  a += n, b += n;
  int ans = 0;
  while(a <= b){
    if (a & 1) ans = max(ans, st[a++]);
    if (~b & 1) ans = max(ans, st[b--]);
    a >>= 1, b >>= 1;
  }
  return ans;
}

void solve() {
  int N, M;
  cin >> N >> M;
  vector<int> arr(N + 1), brr(M + 1);
  for (int i = 1; i <= N; ++i) {
    cin >> arr[i];
  }
  for (int i = 1; i <= M; ++i) {
    cin >> brr[i];
  }
  int us = arr[1];
  sort(arr.begin(), arr.end());
  sort(brr.begin(), brr.end());
  if (us == arr[N]) {
    for (int i = 1; i <= M; ++i) {
      cout << M / i << " \n"[i == M];
    }
    return;
  }
  BIT bit(M + 10);
  st.assign(2 * M + 10, 0);
  n = M;
  int aidx = upper_bound(arr.begin(), arr.end(), us) - arr.begin();
  int bidx = upper_bound(brr.begin(), brr.end(), us) - brr.begin();
  for (int i = aidx; i <= N; ++i) {
    int r = upper_bound(brr.begin(), brr.end(), arr[i]) - brr.begin();
    if (r - 1 >= bidx) {
      bit.range_add(bidx, r - 1, 1);
    }
  }
  for (int i = aidx; i <= N; ++i) {
    upd(i - 1, bit.range_sum(i, i));
  }
  for (int i = 1; i <= M; ++i) {
    int ans = M / i;
    int start = bidx + (M % i);
    for (int j = start; j <= M; j += i) {
      ans += qry(j - 1, j + i - 1);
    }
    cout << ans << " \n"[i == M];
  }
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