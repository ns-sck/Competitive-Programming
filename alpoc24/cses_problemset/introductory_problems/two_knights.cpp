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
    for (int i = 1; i <= n; ++i) {
        int total = i*i*(i*i-1)/2;
        cout << total - 4 * (i-1) * (i-2) << ' ';
    }
    return 0;
}
