#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<vector<int>>
#define mii map<int, int>
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
const int MOD = 1e9+7;

int32_t main() {

    ios;
    int n; cin >> n;
    vi v(n);
    int tot = 0;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        tot += v[i];
    }   
    int ans = LLONG_MAX;
    for (int i = 0; i < (1 << n); ++i) {
        int total = 0;
        for (int j = 0; j < n; ++j) {
            if ((1 << j) & i) {
                total += v[j];
            }
        }
        ans = min(ans, abs(2 * total - tot));
    }
    cout << ans;
    return 0;
}
