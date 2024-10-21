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
    vi a(N + 1);

    for (int i = 1; i <= N; ++i) {
        cin >> a[i];
        a[i] += a[i-1];
    }   

    int ans = 0;

    for (int i = 1; i <= N; ++i) {
        if (N % i) continue;
        int mx = 0, mn = INF;
        for (int j = i; j <= N; j += i) {
            mx = max(mx, a[j] - a[j-i]);
            mn = min(mn, a[j] - a[j-i]);
        }
        ans = max(ans, mx - mn);
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