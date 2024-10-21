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
    int N, Q;
    cin >> N >> Q;

    vi v(N);
    map<int, int> mp;
    map<int, int> cnt;
    for (int& x : v) cin >> x, mp[x] = 0;

    for (int i = 1; i <= Q; ++i) {
        int j, x;
        cin >> j >> x;
        --j;

        int old = v[j];
        if (x == v[j]) continue;

        cnt[old] += i - mp[old];
        mp[x] = i;
        v[j] = x;
    }

    for (int i = 0; i < N; ++i) {
        cnt[v[i]] += Q + 1 - mp[v[i]];
    }

    int ans = Q * (Q + 1) * N;
    for (auto [x, y] : cnt) {
        ans -= y * (y - 1) / 2;
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