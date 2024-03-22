#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define vii vector<vector<int>>
#define pii pair<int, int>
#define ar array

const int INF = 1e18;
const int MOD = 1e9+7;
const int _max = 2e5+1;

int32_t main() {
	
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vi v(n);
        for (int i = 0; i < n; ++i)
            cin >> v[i];
            
        int l = -1e6;
        int h = 1e6;
        int ls = 0;
        int hs = 0;
        int ms = 0;
        
        int ans = 1e18;
        while (l <= h) {
            hs = 0;
            ls = 0;
            ms = 0;
            int mid = (h+l) / 2;
            int u = 0, d = 0;
            for (int i = 0; i < n; ++i) {
                if (v[i] > (mid+i)) {
                    u++;
                } else if (v[i] < (mid+i)) {
                    d++;
                }
                ls += abs(v[i] - (l+i));
                ms += abs(v[i] - (mid+i));
                hs += abs(v[i] - (h+i));
            }
            ans = min({ans, ls, ms, hs});
            if (u > d) {
                l = mid+1;
            } else if (d > u) {
                h = mid-1;
            } else {
                break;
            }
        }

        cout << ans << '\n';
    }
    return 0;
}
