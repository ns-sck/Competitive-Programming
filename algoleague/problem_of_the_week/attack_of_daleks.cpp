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
    if (N > 5000) {
        cout << "Yes\n";
        return;
    }
    vi v(N);
    for (int& x : v) cin >> x;

    sort(all(v));

    map<int, vi> mp;

    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < i; ++j) {
            mp[v[i] ^ v[j]].pb(i);
            if (i > 2 && j > 1) {
                auto& ref = mp[v[i] ^ v[j]];
                auto it = lower_bound(all(ref), j);
                if (it == ref.begin() || !ref.size()) continue;
                cout << "Yes\n";
                return;
            }
        }
    }

    cout << "No\n";
}

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}