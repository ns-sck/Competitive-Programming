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
    int N, A, B;
    cin >> N >> A >> B;

    bool b = !A;
    int bits = 11;
    int l = -B, r = B;

    vvi dp(N, vi(1 << bits));
    for (int i = min(N - 1, B); i >= (A); --i) {
        int sh = 5 - i;
        dp[0][1 << sh] = 1;
    }
    

    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < (1 << bits); ++j) {
            if (!dp[i-1][j]) continue;
            for (int k = min(N - i - 1, B); k >= max(-i, -B); --k) {
                if (k >= 0 && k < A) continue;
                if (k <= 0 && k > -A) continue; 
                int sh = 5 - k;
                int nw = (j << 1) & (~(1 << 11));
                if (((1 << sh) & nw) == 0) {
                    auto& ref = dp[i][(1 << sh) | nw];
                    ref = (ref + dp[i-1][j]) % MOD; 
                }
            }
        }
    }

    int ans = 0;

    for (int j = 0; j < (1 << bits); ++j) {
        ans = (ans + dp[N - 1][j]) % MOD;
        if (ans) put(j);
    }

    put(ans);
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