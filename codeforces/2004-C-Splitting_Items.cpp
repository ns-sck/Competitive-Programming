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
    int N, K;
    cin >> N >> K;
    vi v(N);
    for (int& x : v) cin >> x;
    sort(all(v));
    int ans = 0;
    for (int i = N-2; i >= 0; i -= 2) {
        int diff = v[i+1] - v[i];
        if (K > 0) {
            int sub = min(K, diff);
            diff -= sub;
            K -= sub;
        }
        ans += diff;
    }
    if (N & 1) ans += v[0];
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
