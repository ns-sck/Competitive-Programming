#include <bits/stdc++.h>
using namespace std;

#define int int64_t

const double PI = 2.0 * acos(0.0);
using cd = complex<double>;

void fft(vector<cd> &a, bool invert = 0) {
  int n = a.size();

  for (int i = 1, j = 0; i < n; i++) {
    int bit = n >> 1;
    for (; j & bit; bit >>= 1)
      j ^= bit;
    j ^= bit;

    if (i < j)
      swap(a[i], a[j]);
  }

  for (int len = 2; len <= n; len <<= 1) {
    double ang = 2 * PI / len * (invert ? -1 : 1);
    cd wlen(cos(ang), sin(ang));
    for (int i = 0; i < n; i += len) {
      cd w(1);
      for (int j = 0; j < len / 2; j++) {
        cd u = a[i + j], v = a[i + j + len / 2] * w;
        a[i + j] = u + v;
        a[i + j + len / 2] = u - v;
        w *= wlen;
      }
    }
  }

  if (invert) {
    for (cd &x : a)
      x /= n;
  }
}

vector<int> multiply(vector<int> const &a, vector<int> const &b) {
  vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
  int n = 1;
  while (n < a.size() + b.size())
    n <<= 1;
  fa.resize(n);
  fb.resize(n);

  fft(fa);
  fft(fb);
  for (int i = 0; i < n; i++)
    fa[i] *= fb[i];
  fft(fa, 1);

  vector<int> result(n);
  for (int i = 0; i < n; i++)
    result[i] = round(fa[i].real());

  return result;
}

void solve() {
  int K, N, M;
  cin >> K >> N >> M;
  vector<int> a(K + 1), b(K + 1);
  for (int i = 0; i < N; ++i) {
    int x; cin >> x;
    a[x]++;
  }
  for (int i = 0; i < M; ++i) {
    int x; cin >> x;
    b[x]++;
  }
  vector<int> ans = multiply(a, b);
  for (int i = 2; i <= 2 * K; ++i) {
    cout << ans[i] << ' ';
  }
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