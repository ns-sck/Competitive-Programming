#include <bits/stdc++.h>
using namespace std;

template<typename... T>
void put(T&&... args) { ((cout << args << " "), ...); cout << '\n';}

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
    // 0 1 0 1 1 1 0 1 0
    // 1 0 1 0 0 0 1 0
    // 0 1 0 1 1 1 0
    // 1 0 1 0 0 0 
    // 0 1 0   0 0
    int N; cin >> N;
    vi S(N);
    for (int& x : S) cin >> x;
    if (S[N-1] == 1) {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    bool c = 0;
    int i = N-1;
    while (~i) {
        int len = 1;
        --i;
        while (~i && S[i] == 1) --i, ++len;
        for (int j = 0; j < len-1; ++j)
            cout << 0 << ' ';   
        cout << len-1 << ' ';
    }
    cout << '\n';
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
