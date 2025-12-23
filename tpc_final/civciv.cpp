#include <bits/stdc++.h>

#define int long long
#define endl '\n'

using namespace std;

int32_t main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t; cin >> t;
  while (t--) {

    int n, ans = 0;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v) cin >> i;
    
    vector<int> a, b;
    for (int i = 0; i < n / 2; i++)
    a.push_back(v[i]);
    for (int i = n / 2; i < n; i++)
    b.push_back(v[i]);
    vector<vector<pair<int, int>>> mim(n / 2 + 1);
    int k = n / 2;
    
    for (int i = 0; i < (1 << a.size()); i++)
    {
      int k = i, sum = 0;
      for (int j = 1, t = 0; sum <= m && j <= k; j <<= 1, t++)
      if (k & j)
      sum += a[t];
      
      if (sum <= m)
      val.push_back(sum);
    }
    
    sort(val.begin(), val.end());
    
    for (int i = 0; i < (1 << b.size()); i++)
    {
      int k = i, sum = 0;
      for (int j = 1, t = 0; sum <= m && j <= k; j <<= 1, t++)
      if (k & j)
      sum += b[t];
      
      ans += upper_bound(val.begin(), val.end(), m - sum) - lower_bound(val.begin(), val.end(), m - sum);
    }
    
    cout << ans;
  }

  return 0;
}