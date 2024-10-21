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

void solve() {
    int N; cin >> N;
    int lo = 0, hi = 1e9, ans = INF;

    if (N == 1) {
        put(0);
        return;
    }

    while (lo <= hi) {
        int mi = (lo + hi) >> 1ll;
        int have = 0;
        if (mi & 1) {
            int x = mi >> 1;
            have = 4ll * (x) * (x + 1) + 4 * (x + 1);
        } else {
            int x = mi / 2;
            have = 4ll * (x) * (x + 1) + 1;
        }
        if (have >= N) {
            ans = min(ans, mi);
            hi = mi - 1;
        } else {
            lo = mi + 1;
        }
    }

    put(ans);
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