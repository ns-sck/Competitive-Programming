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
    while (n--) {
        int a, b; cin >> a >> b;
        int z = max(a,b);
        if (z % 2) {
            if (z == a) {
                cout << (z-1) * (z-1) + b << '\n';
            }
            else {
                cout << (z) * (z) - a + 1 << '\n';
            }   
        }
        else {
            if (z == a) {
                cout << (z) * (z) - b + 1<< '\n';
            }
            else {
                cout << (z-1) * (z-1) + a << '\n';
            }
        }
    }
    return 0;
}
