#include <bits/stdc++.h>
using namespace std;

template<typename... T>
void put(T&&... args) { ((cout << args << " "), ...); cout << '\n';}

#define int long long
#define ll long long
#define pi pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpi vector<pi>
#define pb push_back
#define ar array
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

const ll MOD = 1e9+7;
const ll INF = 1e18;
const ll MAX = 2e5+1;

int prefixor(int n) {
    if (n % 4 == 0) return n;
    if (n % 4 == 1) return 1;
    if (n % 4 == 2) return n + 1;
    return 0;
}

void solve() {
    int L, R, j, K;
    cin >> L >> R >> j >> K;

    int x = 1 << j;
    int l = L, r = R;
    
    if (r % x < K) {
        r -= x + r % x - K;
    } else {
        r -= r % x - K;
    }
    if (l % x <= K) {
        l -= l % x - K;
    } else {
        l -= l % x - x - K;
    }

    int ans = prefixor(R) ^ prefixor(L - 1);
    if (l <= r) {
        l >>= j;
        r >>= j;
        int y = prefixor(r) ^ prefixor(l - 1);
        if ((l - r + 1) & 1) {
            ans ^= K;
        }
        y <<= j;
        cout << (ans ^ y) << '\n';
    } else cout << ans << '\n';
}

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}