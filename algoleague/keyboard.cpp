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

    vi a(N), b(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i] >> b[i];
    }

    vvi dis(N, vi(N));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            dis[i][j] = abs(a[i] - a[j]) + abs(b[i] - b[j]);
        }
    }

    vvi dp(N, vi(N, INF));

    dp[0][1] = 0, dp[1][0] = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i == j) continue;
            if (i > j) {
                dp[i][j] = min(dp[i][j], dp[i-1][j] + dis[i-1][i]);
                if (i == j + 1) {
                    for (int k = 0; k < j; ++k) {
                        dp[i][j] = min(dp[i][j], dp[k][j] + dis[k][i]);
                    }
                }
            } else {
                dp[i][j] = min(dp[i][j], dp[i][j-1] + dis[j-1][j]);
                if (j == i + 1) {
                    for (int k = 0; k < i; ++k) {
                        dp[i][j] = min(dp[i][j], dp[i][k] + dis[k][j]);
                    }
                }
            }
        }
    }

    int ans = INF;
    for (int i = 0; i < N; ++i) {
        ans = min(ans, dp[i][N-1]);
        ans = min(ans, dp[N-1][i]);
    }

    cout << ans << '\n';
}

// 4 2 1 3 0

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}