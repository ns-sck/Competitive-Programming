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
    int last = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int a; cin >> a;
        if (last > a) {
            ans += last-a;
        }
        last = max(a, last);
    }
    cout << ans;
    return 0;
}
