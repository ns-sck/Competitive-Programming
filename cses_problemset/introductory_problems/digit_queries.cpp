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
    int q; cin >> q;
    while (q--) {
        int k; cin >> k;
        int mult = 1, dig = 1;
        int total = 0;
        while (9 * mult * dig + total < k) {
            total += 9 * mult * dig;
            mult *= 10;
            dig += 1;
        }
        k -= total;
        int incr = (k-1) / dig;
        int num = pow(10, dig-1);
        num += incr;
        int mod = k % dig;
        if (mod == 0) {
            string number = to_string(num);
            cout << number[number.length()-1] << '\n';
        }
        else {
            string number = to_string(num);
            cout << number[mod-1] << '\n';
        }
    }
    
    return 0;
}
