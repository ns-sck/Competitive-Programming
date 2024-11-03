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
    int N, M;
    cin >> N >> M;

    vi A(N), B(M);

    for (int& x : A) cin >> x;
    for (int& x : B) cin >> x;

    A.pb(0);
    vi prfx = A;

    for (int i = 0; i < N; ++i) {
        prfx[i+1] += prfx[i];
    }

    vvi dp(N + 1, vi(M, INF));

    for (int j = 0; j < M; ++j) dp[0][j] = 0;

    for (int j = 0; j < M; ++j) {
        for (int i = 0; i < N; ++i) {
            if (j) dp[i][j] = min(dp[i][j], dp[i][j-1]);
            int go = B[j] + (i ? prfx[i-1] : 0);  
            auto it = upper_bound(all(prfx), go);
            if (it == prfx.begin()) continue;
            int k;
            if (it == prfx.end()) {
                k = N;
            } else k = it - prfx.begin();
            dp[k][j] = min(dp[k][j], dp[i][j] + M - j - 1);
        }
    }

    int ans = INF;
    for (int j = 0; j < M; ++j) {
        ans = min(ans, dp[N][j]);
    }

    if (ans == INF) put(-1);
    else put(ans);

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