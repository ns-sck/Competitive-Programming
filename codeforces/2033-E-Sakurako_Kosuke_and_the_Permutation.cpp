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
    vi v(N);
    vi pos(N);
    for (int& x : v) cin >> x, --x;
                                    
    for (int i = 0; i < N; ++i) pos[v[i]] = i;

    int ans = 0;

    for (int i = 0; i < N; ++i) {
        if (v[i] == i || v[v[i]] == i) continue;
        int x = v[i];
        int a = v[x], b = i;
        swap(v[x], v[pos[i]]);
        pos[a] = pos[i];
        pos[i] = x;
        ++ans;
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