#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t

struct point2d {
  double x, y;
  point2d() {}
  point2d(double x, double y) : x(x), y(y) {}
  point2d& operator+=(const point2d& t) {
    x += t.x;
    y += t.y;
    return *this;
  }
  point2d& operator-=(const point2d& t) {
    x -= t.x;
    y -= t.y;
    return *this;
  }
  point2d& operator*=(double t) {
    x *= t;
    y *= t;
    return *this;
  }
  point2d& operator/=(double t) {
    x /= t;
    y /= t;
    return *this;
  }
  point2d operator+(const point2d& t) const { return point2d(*this) += t; }
  point2d operator-(const point2d& t) const { return point2d(*this) -= t; }
  point2d operator*(double t) const { return point2d(*this) *= t; }
  point2d operator/(double t) const { return point2d(*this) /= t; }
};
point2d operator*(double a, point2d b) { return b * a; }
double dot(point2d a, point2d b) { return a.x * b.x + a.y * b.y; }

void solve() {
  int A, B, C, D, E, F;
  cin >> A >> B >> C >> D >> E >> F;
  C -= A, E-= A, A = 0;
  D -= B, F -= B, B = 0;
  double x = C / 2 + 0.1, y = D / 2;
  
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}