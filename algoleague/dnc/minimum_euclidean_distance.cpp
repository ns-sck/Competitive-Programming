// https://cses.fi/problemset/task/2194

#include <bits/stdc++.h>
using namespace std;

#define int int64_t
constexpr int MAX = 2e5 + 1;
int X[MAX];
int Y[MAX];
bool lft[MAX];
int best = LLONG_MAX;

inline int square(int x) {
  return x * x;
}

inline void upd(int i, int j) {
  int dx = X[i] - X[j];
  int dy = Y[i] - Y[j];
  best = min(best, dx * dx + dy * dy);
}

void dnc(vector<int> sortedX, vector<int> sortedY) {
  int N = sortedX.size();
  if (N == 1) return;
  vector<int> lx, ly, rx, ry;
  for (int i = 0; i < N; ++i) {
    if (i < N / 2) {
      lx.emplace_back(sortedX[i]);
      lft[sortedX[i]] = 1;
    } else {
      rx.emplace_back(sortedX[i]);
      lft[sortedX[i]] = 0;
    }
  }
  for (int id : sortedY) {
    if (lft[id]) {
      ly.emplace_back(id);
    } else {
      ry.emplace_back(id);
    }
  }
  dnc(lx, ly);
  dnc(rx, ry);
  int midX = X[lx.back()];
  vector<int> strip;
  for (int id : sortedY) {
    if (square(X[id] - midX) <= best) {
      strip.emplace_back(id);
    }
  }
  for (int i = 0; i < strip.size(); ++i) {
    for (int j = i + 1; j < strip.size() && square(Y[strip[j]] - Y[strip[i]]) < best; ++j) {
      upd(strip[i], strip[j]);
    }
  }
}

void solve() {
  int N;
  cin >> N;
  vector<int> sortedX, sortedY;
  for (int i = 0; i < N; ++i) {
    cin >> X[i] >> Y[i];
    sortedX.emplace_back(i);
    sortedY.emplace_back(i);
  }
  sort(sortedX.begin(), sortedX.end(), [](int i, int j) {
    return X[i] < X[j];
  });
  sort(sortedY.begin(), sortedY.end(), [](int i, int j){
    return Y[i] < Y[j];
  });
  dnc(sortedX, sortedY);
  cout << best << '\n';
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