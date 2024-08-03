#include <bits/stdc++.h>
using namespace std;

template<typename... T>
void dbg(T&&... args) { ((cout << args << " "), ...); cout << endl;}

#define int long long
#define ll long long
#define ld long double
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
const ll MAX = 101;

int dp[MAX][MAX];

void solve() {
    int N, L;
    cin >> N >> L;

    auto add = [&](int& x, int y) {
        x = (x + y) % MOD;
    };

    dp[1][0] = 1;

    for (int tot = 2; tot <= N; ++tot) {
        for (int sub = 1; sub < tot; ++sub) {
            for (int i = 0; i < sub; ++i) {
                for (int j = 0; j < tot-sub; ++j) {
                    add(dp[tot][max(i, j+1)], dp[sub][i] * dp[tot-sub][j]);
                }
            }
        }
    }

    //   |a|        
    //  |a a|  --> dp[sub][i] -> dp[3][1]

    //    |a|
    //  |a a| a
    //          a  --> dp[sub][i] * dp[tot-sub][j] -> dp[3][1] * dp[2][1] -> dp[5][max(1, 1+1)] 

    int ans = 0;
    for (int d = L; d <= N; ++d) {
        add(ans, dp[N][d]);
    }

    cout << ans << '\n';
}

signed main () {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}
