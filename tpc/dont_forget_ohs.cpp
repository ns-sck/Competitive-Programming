#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t

string days[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void solve() {
  int N;
  cin >> N;
  int year = 2024, month = 3, day = 10, period = 1461, n = N;
  year += n / period * 4;
  n %= period;
  for (int i = 0; i < n; ++i) {
    day++;
    // months array is 0 indexed so [month - 1]
    // year % 4 == 0 -> this is a leap year
    // if month is 2, February is 29 instead of 28
    if (day > (months[month - 1] + (month == 2 && year % 4 == 0))) {
      day = 1;
      month++;
      if (month > 12) {
        month = 1;
        year++;
      }
    }
  }
  auto f = [](int x) {
    if (x > 9) return to_string(x);
    return '0' + to_string(x);
  };
  cout << f(day) << '.' << f(month) << '.' << year << ' ' << days[N % 7] << '\n';
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