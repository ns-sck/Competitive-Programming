#include <bits/stdc++.h>
using namespace std;

#define int uint32_t

// template from tourist
template <typename T, size_t N, size_t M, size_t K>
array<array<T, K>, N> operator*(const array<array<T, M>, N>& a, const array<array<T, K>, M>& b) {
  array<array<T, K>, N> c;
  for (size_t i = 0; i < N; i++) {
    for (size_t j = 0; j < K; j++) {
      c[i][j] = 0;
      for (size_t k = 0; k < M; k++) {
        c[i][j] += a[i][k] * b[k][j];
      }
    }
  }
  return c;
}

template <typename T>
vector<vector<T>> operator*(const vector<vector<T>>& a, const vector<vector<T>>& b) {
  if (a.empty() || b.empty()) {
    return {{}};
  }
  vector<vector<T>> c(a.size(), vector<T>(b[0].size()));
  for (int i = 0; i < static_cast<int>(c.size()); i++) {
    for (int j = 0; j < static_cast<int>(c[0].size()); j++) {
      c[i][j] = 0;
      for (int k = 0; k < static_cast<int>(b.size()); k++) {
        c[i][j] += a[i][k] * b[k][j];
      }
    }
  }
  return c;
}

template <typename T>
vector<vector<T>>& operator*=(vector<vector<T>>& a, const vector<vector<T>>& b) {
  return a = a * b;
}

template <typename T, typename U>
vector<vector<T>> power(const vector<vector<T>>& a, const U& b) {
  assert(b >= 0);
  vector<U> binary;
  U bb = b;
  while (bb > 0) {
    binary.push_back(bb & 1);
    bb >>= 1;
  }
  vector<vector<T>> res(a.size(), vector<T>(a.size()));
  for (int i = 0; i < static_cast<int>(a.size()); i++) {
    res[i][i] = 1;
  }
  for (int j = (int) binary.size() - 1; j >= 0 && j <= 1000; j--) {
    res *= res;
    if (binary[j] == 1) {
      res *= a;
    }
  }
  return res;
}

void solve() {
  int K;
  cin >> K;
  vector<vector<int>> mtx(65, vector<int>(65));
  auto ok = [&](int r, int c) -> bool {
    return r >= 0 && r < 8 && c >= 0 && c < 8;
  };
  vector<pair<int, int>> dir = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
  for (int i = 0; i < 8; ++i) {
    for(int j = 0; j < 8; ++j) {
      for (auto [x, y] : dir) {
        int ii = i + x;
        int jj = j + y;
        if (!ok(ii, jj)) continue;
        mtx[8 * i + j][8 * ii + jj] = 1;
      }
    }
  }
  for (int i = 0; i <= 64; ++i) {
    mtx[i][64] = 1;
  }
  auto tot = power(mtx, K);
  cout << tot[0][64] << '\n';
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