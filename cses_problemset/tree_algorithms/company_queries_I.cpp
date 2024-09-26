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

int par[MAX][20];

void solve() {

    int N, Q;
    cin >> N >> Q;

    for (int i = 2; i <= N; ++i) {
        int x; cin >> x;
        par[i][0] = x;
    }

    for (int i = 1; i < 20; ++i) {
        for (int j = 2; j <= N; ++j) {
            par[j][i] = par[par[j][i-1]][i-1];
        }
    }

    while (Q--) {
        int u, k;
        cin >> u >> k;

        for (int i = 20; ~i; --i) {
            if ((1 << i) > k) continue;
            u = par[u][i];
            k -= (1 << i);
        }

        cout << (u | -!u) << '\n';
    }
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
