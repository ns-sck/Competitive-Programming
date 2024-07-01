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

void solve() {
    int N, A, B;
    cin >> N >> A >> B;
    // b-i+1 > a
    // i < b-a+1
    int ans = 0;
    int i = min(N, B-A);
    if (i < 1) cout << N*A << '\n';
    else {
        ans += i*((double)(B+(B-i)+1)/2.0);
        ans += (N-i)*A;
        cout << ans << '\n';
    }
    // 5 4 4 4
    // 10 9 8 7 6 5 5 5 5 5
    // 9 8 7 6 5
    // 5 5 9
    // 11 10 9 8 7
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
