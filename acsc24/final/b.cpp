#include <bits/stdc++.h>
using namespace std;

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
const ll MAX = 2e5+1;
string S;
int M, N;
ll x, ans = -1, pw;
int dp[1<<19][26];
int fp(int base, int exp) {
    int rval = 1LL;
    while (exp) {
        if (exp & 1) {
            rval *= base;
            rval %= MOD;
        }
        base *= base;
        base %= MOD;
        exp >>= 1;
    }
    return rval;
}
bool b = 0;
int dfs(int idx, int msk, int md) {
    auto& ref = dp[msk][md];
    if (~ref) return ref;
    if (idx == N-1) {
        for (int i = 0; i < N; ++i) {
            if ((1<<i)& msk) continue;
            if ((S[i]-'0') % M == 0) {
                return S[i]-'0';
                b = 1; 
            }
            else return -1;
        }
    }
    int pw = fp(10, N-idx-1);
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        if ((1<<i) & msk) continue;
        int z = pw*(S[i]-'0');
        int x = dfs(idx+1, msk | i, M-(z%M));
        if (x == -1) continue;
        ans = max(ans, z+x);
    }
    return ref = ans;
}

void solve() {
    cin >> S >> M;
    N = S.size();
    pw = fp(10, N-1);
    dfs(0, 0, 0);
    memset(dp, -1, sizeof(dp));
    int a = 0;
    for (int i = 0; i < N; ++i) {
        int t = (S[i]-'0')*pw;
        int z = dfs(1, 1<<i, M-(t%M));
        if ((z) == -1) continue;
        else a = max(a, t+z);
    }
    if (!b) cout << -1;
    else cout << a << '\n';
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
