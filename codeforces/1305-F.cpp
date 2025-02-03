#include <bits/stdc++.h>
using namespace std;

#define int int64_t

int arr[200000];

void solve() {
  int N;
  cin >> N;
  int ans = N, c = 0;
  for (int i = 0; i < N; ++i) {
    cin >> arr[i];
    if (arr[i] == 1) {
      ++c;
      ++arr[i];
    }
  } 
  int lg = 6;
  sort(arr, arr + N);
  map<int, int> mp;
  for (int i = arr[0] - lg, j = -lg; i <= arr[0] + lg; ++i, ++j) {
    if (i > 1) mp[i] = abs(j);
  }
  for (int k = 1; k < N; ++k) {
    map<int, int> temp;
    for (int i = arr[k] - lg, j = -lg; i <= arr[k] + lg; ++i, ++j) {
      if (i > 0) {
        for (auto& [x, y] : mp) {
          int z = __gcd(x, i);
          if (z == 1) continue;
          if (temp.count(z)) temp[z] = min(temp[z], y + abs(j));
          else temp[z] = y + abs(j);
        }
      }
    }
    mp = temp;
  } 
  for (auto& [x, y] : mp) {
    ans = min(ans, y);
  }
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  mp.clear();
  for (int i = 0; i < 100; ++i) {
    int a = rng() % N, b = rng() % N;
    int z = __gcd(arr[a], arr[b]);
    if (z == 1) continue;
    ++mp[z];
  }
  for (auto& [a, y] : mp) {
    int num = a;
    vector<int> divs;
    for (int i = 2; i * i <= num; ++i) {
      if (num % i) continue;
      while ((num % i) == 0) num /= i;
      divs.emplace_back(i);
    }
    divs.emplace_back(a);
    int ans2 = 0;
    if (num > 1) divs.emplace_back(num);
    for (int i = 0; i < N; ++i) {
      auto it = lower_bound(divs.begin(), divs.end(), arr[i]);
      int diff = 1ll << 61;
      if (it != divs.end()) diff = abs(*it - arr[i]);
      if (it != divs.begin()) {
        --it;
        diff = min(diff, abs(*it - arr[i]));
      }
      ans2 += diff;
    }
    ans = min(ans, ans2);
  }
  cout << ans + c << '\n';
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