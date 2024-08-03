#include <bits/stdc++.h>
using namespace std;
 
template<typename... T>
void dbg(T&&... args) { ((cout << args << " "), ...); cout << '\n';}
 
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
const ll MAX = 1e3+1;
 
void solve() {
	int N, K;
    cin >> N >> K;
    int x = (N-1+K-2) / K-1;
    dbg(x);
}
 
signed main () {
 
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
	int t = 1;
	cin >> t;
	while (t--) solve();
 
	return 0;
}