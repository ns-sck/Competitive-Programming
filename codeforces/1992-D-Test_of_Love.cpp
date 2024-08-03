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

int N, M, K;
string S;
bool b = 0;
void f(int i, int left, vi& dp) {
    if (i == N+1) {
        b = 1;
        return;
    }
    int jmp = 0;
    if (dp[i] >= left) return;
    dp[i] = left;
    if (S[i] == 'L') {
        for (int j = min(N+1, i+M); j > i; --j) {
            if (S[j] == 'L') {
                f(j, left, dp);
                jmp = j;
                break;
            }
        }
        for (int j = min(N+1, i+M); j > max(i, jmp); --j) {
            if (S[j] == 'W') {
                f(j, left, dp);
                break;
            }
        }
    }
    if (S[i] == 'W' && left && S[i+1] != 'C') f(i+1, left-1, dp);  
}
void solve() {
    cin >> N >> M >> K;
    S = 'L';
    string s; cin >> s;
    S += s;
    S += 'L';
    b = 0;
    vi dp(N+1, -1);
    f(0, K, dp);
    cout << (b ? "YES\n" : "NO\n");
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
