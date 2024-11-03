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
    vi v(N), need(N);

    for (int& x : v) cin >> x;
    map<int, int> dp;
    map<int, vi> idx;

    vi a;

    for (int i = 0; i < N; ++i) {
        int nd = v[i] - N + i;
        if (nd > -1) need[i] = nd;
        else need[i] = -1;
        idx[need[i]].pb(i);
        a.pb(need[i]);
    }

    sort(all(a));
    int S = a.size();

    for (int i = S - 1; ~i; --i) {
        for (auto j : idx[a[i]]) {
            dp[a[i]] = max(dp[a[i]], j);
            dp[a[i]] = max(dp[a[i]], dp[a[i] + j] + j);
        }
    }

    put(dp[0] + N);
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