#include <bits/stdc++.h>

#define int long long
#define endl '\n'

using namespace std;

const int MOD = 1e9 + 7;
const int INF = 1e18;


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  int t; cin >> t;
  while (t--)
  {
    int a, b, L; cin >> a >> b >> L;

    double s = (double) (-a * b) / (double)(a * a + 1);
    double l = (double)L / 2;

    cout << fixed << setprecision(6);
    cout << sqrt(l * l + s * s + (s * (double)a + (double)b) * (s * (double)a + (double)b)) << endl;
  }
  
  return 0;
}