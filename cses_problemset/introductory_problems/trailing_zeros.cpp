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
    int ans = 0;
    // from William Lin
    for (int i = 5; i <= n; i *= 5) {
        ans += n/i;
    }
    cout << ans;
    return 0;
}
