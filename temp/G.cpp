#include <bits/stdc++.h>

#define int long long
#define MOD 1000000007

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        bool yes = 1;
        for (int i = 0; i < n - 1; ++i) {
            int a = abs(v[i + 1] - v[i]);
            if ((a / 7) == 1 || (a / 5) == 1) {
                continue;
            }
            else {
                yes = 0;
                break;
            }
        }
        if (yes) cout << "YES\n";
        else cout << "NO\n";
    }
    
    return 0;
}