#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define vi vector<int>
#define mii map<int, int>
#define vii vector<vector<int>>
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
const int MOD = 1e9+7;

int32_t main() {

    ios;
    int n, a, d, p;
    cin >> n >> a >> d >> p;
    vi x(1e6+1);
    vi y(1e6+1);
    for (int i = 0; i < n; ++i) {
        int a1, d1;
        cin >> d1 >> a1;
        if (a1 > p + a || d1 > p + d)
            continue;
        if (a1 >= a && d1 >= d && a1 - a + d1 - d > p)
            continue;
        if (a >= a1)
            x[0]++;
        else
            x[a1-a]++;
        if (d >= d1)
            y[0]++;
        else
            y[d1-d]++;
    }
    for (int i = 1; i <= p; ++i) {
        x[i] += x[i-1];
        y[i] += y[i-1];
    }
    int ans = 0;
    for (int i = 0; i <= p; ++i) {
        ans = max(ans, x[p] - (y[p] - y[p-i] + x[p] - x[i]));
    }
    cout << ans << '\n';
    
    return 0;
}
