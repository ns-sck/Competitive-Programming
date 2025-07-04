// author: erray
#include <bits/stdc++.h>

#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
#endif

using namespace std;

struct Fract {
  int t, b;
  Fract() { t = 0, b = 1; } 
  Fract(int64_t x, int64_t y) {
    t = x, b = y;
    if (b < 0) {
      b *= -1, t *= -1;
    }
  }
};
bool operator==(Fract a, Fract b) {
  return 1LL * a.t * b.b == 1LL * a.b * b.t;
}
bool operator>(Fract a, Fract b) {
  return 1LL * a.t * b.b > 1LL * a.b * b.t;
}
bool operator>=(Fract a, Fract b) {
  bool res = (a > b) || (a == b);
  return res;
}

Fract cross(array<int, 2> f0, array<int, 2> f1) {
  return Fract(f1[0] - f0[0], f0[1] - f1[1]);
} 

vector<array<int, 2>> convex_hull(vector<int> a) {
  int n = int(a.size());
  vector<array<int, 2>> res;
  for (int i = 0; i < n; ++i) {
    array<int, 2> add{a[i], i};
    while (int(res.size()) > 1 && cross(res.end()[-1], add) >= cross(res.end()[-1], res.end()[-2])) {
      res.pop_back();
    }
    res.push_back(add);
  }
  return res;
} 

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N, M;
  cin >> N >> M;
  assert(1 <= N && N <= int(5e5) && 1 <= M && M <= int(5e5));
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
    if (A[i] < 0 || A[i] > int(2e9)) {
      cerr << A[i];
      assert(false);
    }
  }
  vector<int> B(M);
  for (int i = 0; i < M; ++i) {
    cin >> B[i];
    assert(0 <= B[i] && B[i] <= int(2e9));
  }
  auto hull_a = convex_hull(A);
  auto hull_b = convex_hull(B);
  int sa = int(hull_a.size());
  int sb = int(hull_b.size());
  Fract never = {int(1e9) + 7, -1};
  int64_t ans = 0;
  int pa = 0, pb = 0;
  while (pa < sa - 1 || pb < sb - 1) {
    Fract cross_a = (pa == sa - 1 ? never : cross(hull_a[pa], hull_a[pa + 1])); 
    Fract cross_b = (pb == sb - 1 ? never : cross(hull_b[pb], hull_b[pb + 1]));
    int cur_a = hull_a[pa][1];
    int cur_b = hull_b[pb][1];
    if (cross_a > cross_b) {
      ans += 1LL * (hull_a[pa + 1][1] - hull_a[pa][1]) * B[cur_b];
      pa++;
    } else {
      ans += 1LL * (hull_b[pb + 1][1] - hull_b[pb][1]) * A[cur_a];
      pb++;
    }
  }
  cout << ans << '\n';
}