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
    map<int, int> mp, mp2;
    for (int& x : v) cin >> x, ++mp[x], ++mp2[x];

    int l = 0;
    int j = 0;

    for (auto& [x, y] : mp) {
        if (mp.count(x - 1)) {
            y += l;
            l = y;
        } else {
            l = y;
        }
    }

    set<int> s;
    int bg = 0;
    int ans = 0;

    for (auto [x, y] : mp) {
        if (s.empty()) {
            s.insert(x);
            ans = max(ans, y);
        } else if (x > *s.rbegin() + 1) {
            s.clear();
            s.insert(x);
            ans = max(ans, mp2[x]);
        } else {
            s.insert(x);
            auto it = s.lower_bound(x - K + 1);
            if (it == s.begin()) {
                ans = max(ans, y);
            } else {
                --it;
                ans = max(ans, mp[x] - mp[*it]);
            }
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