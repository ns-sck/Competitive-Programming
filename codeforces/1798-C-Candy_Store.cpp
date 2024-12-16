#include <bits/stdc++.h>
using namespace std;

#define int int64_t

int gcd(int a, int b) {
  while (b != 0) {
    int temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

int lcm(int a, int b) {
  return (a / gcd(a, b)) * b;
}

void solve() {
  int N;
  cin >> N;
  vector<int> a(N), b(N);
  for (int i = 0; i < N; ++i) {
    cin >> a[i] >> b[i];
  }
  int i = 1, last = b[0], ans = 1, arrv = a[0];
  while (i < N) {
    int g = lcm(b[i], last);
    bool bl = (a[i] % (g / b[i])) == 0;
    bl &= (arrv % (g / last)) == 0;
    arrv /= g / last;
    arrv = gcd(arrv, a[i] / (g / b[i]));
    if (bl) {
      last = g;
    } else {
      ++ans;
      last = b[i];
      arrv = a[i];  
    }
    ++i;
  }
  cout << ans << '\n';
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