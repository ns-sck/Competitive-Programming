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

    int n; cin >> n;
    vi v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    vi ans;
    vector<int> dp(1e5+1);
    dp[0] = true;
    for (int j = 0; j < n; ++j) {
        for (int i = 1e5; i > 0; --i) {
            if (v[j] <= i)
                dp[i] |= dp[i-v[j]];
        }
    }
    for (int i = 1; i <= 1e5; ++i)
        if (dp[i]) ans.push_back(i);

    cout << ans.size() << '\n';
    for (auto x : ans)
        cout << x << ' ';
    return 0;
}
