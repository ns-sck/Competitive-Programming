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
    cout << n << ' ';
    while (n != 1) {
        if (n % 2 == 0) {
            n >>= 1;
        }
        else {
            n = 3*n + 1;
        }
        cout << n << ' ';
    }
    
    return 0;
}
