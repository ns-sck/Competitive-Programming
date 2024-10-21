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

    vvi v = {{}};
    int j = 0;
    for (int i = 0; i < N; ++i) {
        int x; cin >> x;
        if (v[j].size() && (v[j].back() & 1) == (x & 1)) {
            v.pb({x});
            ++j;
        } else v[j].pb(x);
    }

    int ans = -INF;
    for (vi& vc : v) {
        int n = vc.size();
        int a = -INF, t = 0;
        for (int i = 0; i < n; ++i) {
            a = max(a, vc[i]);
            if (vc[i] + t < 0) t = 0;
            else {
                t += vc[i];
                a = max(a, t);
            }
        }
        ans = max(a, ans);
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