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
    
    int N, L, U;
    cin >> N >> L >> U;
    int sz1 = N >> 1, sz2 = N - sz1;
    vi v1(sz1), v2(sz2);
    for (int i = 0; i < sz1; ++i) cin >> v1[i];
    for (int i = 0; i < sz2; ++i) cin >> v2[i];

    vi a1, a2;
    for(int i = 0; i < (1 << sz1); ++i) {
        int x = 0;
        for (int j = 0; j < sz1; ++j) {
            if ((i >> j) & 1) {
                x += v1[j];
            }
        }
        a1.pb(x);
    }
    for(int i = 0; i < (1 << sz2); ++i) {
        int x = 0;
        for (int j = 0; j < sz2; ++j) {
            if ((i >> j) & 1) {
                x += v2[j];
            }
        }
        a2.pb(x);
    }

    sort(all(a2));
    int ans = 0;

    for (int i = 0; i < (1 << sz1); ++i) {
        int l = lower_bound(all(a2), L - a1[i]) - a2.begin();
        int u = upper_bound(all(a2), U - a1[i]) - a2.begin();
        ans += u-l;
    }
    cout << ans << '\n';
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
