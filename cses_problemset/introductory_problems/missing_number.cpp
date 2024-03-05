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
    int t = 0;
    for (int i = 0; i < n-1; ++i) {
        int a; cin >> a;
        t += a;
    }
    cout << n * (n+1) / 2 - t;
    return 0;
}
