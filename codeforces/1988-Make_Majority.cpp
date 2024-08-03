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
const ll MAX = 2e5+1;

void solve() {
	int N; cin >> N;
    string S; cin >> S;
    int o = 0, z = 0;
    for (int i = 0; i < N; ++i) {
        if (S[i] == '1') ++o;
        else {
            while (i < N && S[i] == '0') {
                ++i;
            }
            ++z;
            --i;
        }
    }
    cout << (o > z ? "Yes\n" : "No\n");

}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
