#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

// User function Template for C++


    vector<int> minLengthQuery(vector<int>& arr, int x, vector<vector<int>>& queries) {
        // code here
        int iii = 0;
        for (auto& que : queries) {
            que.push_back(iii);
            iii++;
        }
        sort(queries.begin(), queries.end());
        int n = arr.size();
        vector<pair<int, int>> st(2 * n + 2);
        auto upd = [&](int i, int x) {
            i += n;
            st[i] = {x, i - n};
            i >>= 1;
            while (i >= 1) {
                st[i] = min(st[2 * i], st[2 * i + 1]);
                i >>= 1;
            }
        };
        auto qry = [&](int l, int r) {
            l += n;
            r += n;
            pair<int, int> ans = {1 << 30, 0};
            while (l <= r) {
                if (l & 1) {
                    ans = min(ans, st[l++]);
                }
                if (~r & 1) {
                    ans = min(ans, st[r--]);
                }
                l >>= 1;
                r >>= 1;
            }
            return ans;
        };
        
        vector<int> bits(31);
        int r = 0, l = 0;
        while (r < n) {
            int val = arr[r];
            for (int i = 0; i < 31; ++i) {
                if ((val >> i) & 1) {
                    bits[i]++;
                }
            }
            bool ok = (l == r && arr[r] > x);
            while (l < r) {
                int cur = 0;
                for (int i = 0; i < 31; ++i) {
                    cur |= (int)(bits[i] > 0) << i;
                }
                if (cur >= x) {
                    ok = true;
                }
                int curr = 0;
                val = arr[l];
                for (int i = 0; i < 31; ++i) {
                    if ((val >> i) & 1) {
                        bits[i]--;
                    }
                }
                for (int i = 0; i < 31; ++i) {
                    curr |= (int)(bits[i] > 0) << i;
                }
                if (curr < x) {
                    for (int i = 0; i < 31; ++i) {
                        if ((val >> i) & 1) {
                            bits[i]++;
                        }
                    }
                    break;
                }
                l++;
            }
            if (ok) {
                upd(r, r - l + 1);
            }
            else {
                upd(r, 1 << 30);
            }
            r++;
        }
        vector<int> ans(queries.size(), -1);
        for (int i = 0; i < queries.size(); ++i) {
            int l = queries[i][0];
            int r = queries[i][1];
            int k = queries[i][2];
            for (int j = 0; j < r - l + 1; ++j) {
                auto p = qry(l, r);
                if (p.second - p.first + 1 < l) {
                    upd(p.second, 1 << 30);
                }
                else {
                    ans[k] = p.first;
                    break;
                }
            }
        }
        return ans;
    }
void solve() {
  int N;
  cin >> N;
  vector<int> arr(N);
  vector<vector<int>> qr;
  for (int i = 0; i < N; ++i){
    cin >> arr[i];
  }
  int x; cin >> x;
  int q; cin >> q;
  for (int i = 0; i < q; ++i){
    int a, b; cin >> a >> b;
    qr.push_back({a, b});
  }
  vector<int> ans = minLengthQuery(arr, x, qr);
  for (auto xxxx : ans) cout << xxxx << ' ';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}