#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define ld long double
#define pi pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpi vector<pi>
#define pb push_back
#define ar array
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const ll MAX = 2e4;
const ld EPS = 1e-9;
int s[130000];
void solve() {
  int N;
  cin >> N;
  int t = N * (N + 1) / 2;
  if (t & 1) {
    cout << 0 << '\n';
    return;
  }

  s[0] = 1;
  for (int i = 1; i <= N; ++i) {
    for (int j = t / 2; j; --j) {
      if (j - i >= 0) s[j] = (s[j] + s[j - i]) % MOD;
    }
  }
  cout << (s[t >> 1] * 500000004) % MOD << '\n';
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  // cin >> t;
  while (t--) solve();

  return 0;
}
