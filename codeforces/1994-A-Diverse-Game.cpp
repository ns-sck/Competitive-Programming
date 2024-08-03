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
	int N, M;
    cin >> N >> M;
    map<int, int> mp;
    vvi a(N, vi(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> a[i][j];
            ++mp[a[i][j]];
        }
    }
    int left = N*M;
    for (auto [x, c] : mp) {
        if (c > left/2) {
            cout << -1 << '\n';
            return;
        }
    }
    vvi b = a;
    bool bl = 1;

    while (bl) {
        bl = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (a[i][j] != b[i][j]) continue;
                bool b2 = 1;
                for (int k = 0; k < N && b2; ++k) {
                    for (int m = 0; m < M && b2; ++m) {
                        if (b[i][j] != a[k][m] && b[k][m] != a[i][j]) {
                            swap(b[i][j], b[k][m]);
                            b2 = 0;
                            bl = 1;
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << b[i][j] << ' ';
        }
        cout << '\n';
    }
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
