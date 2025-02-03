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
    if (n % 4 == 1 || n % 4 == 2) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    if (n % 4 == 3) {
        int a = n/4;
        cout << 2*a+1 << '\n';
        for (int i = 0; i < a+1; ++i) {
            cout << n-i << ' ';
        }
        for (int i = 0; i < a; ++i) {
            cout << i+1 << ' ';
        }
        cout << '\n' << n/2+1 << '\n';
        for (int i = a; i < a + n/2 + 1; ++i) {
            cout << i+1 << ' ';
        }
    } else {
        int a = n/4;
        cout << 2*a << '\n';
        for (int i = 0; i < a; ++i) {
            cout << i+1 << ' ' << n-i << ' ';
        }
        cout << '\n' << 2*a << '\n';
        for (int i = a; i < a + n/2; ++i) {
            cout << i+1 << ' ';
        }
    }

    return 0;
}
