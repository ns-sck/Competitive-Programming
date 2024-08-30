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
int N, C, K, ans = INF;
string S;
vector<set<int>> idx;

void dfs(int i, int t, int mask) {
    if (i >= N) {
        ans = min(ans, t);
        return;
    }
    int last = S[N-1]-'A';

    if (i == N-1) {
        t += (((mask >> last) & 1) == 0);
        ans = min(ans, t);
        return;
    }

    bool sent = 0;
    if (i + K >= N) {
        ans = min(ans, t + (((mask >> last) & 1) == 0));
    }
    for (int j = C-1; ~j; --j) {
        if (((mask >> j) & 1) == 1) {
            auto it = idx[j].lower_bound(i);
            if (it != idx[j].end()) {
                int x = *it;
                if (x < i + K) {
                    dfs(x+1, t, mask);
                    break;
                }
            }
        } else if (((mask >> j) & 1) == 0){
            auto it = idx[j].lower_bound(i);
            if (it != idx[j].end()) {
                int x = *it;
                if (x < i + K) {
                    dfs(x+1, t+1, mask | (1 << j));
                }
            }
        }
    }
}
void solve() {
    cin >> N >> C >> K >> S;
    // ABDBCBABCBADBCAABCBDDD
    idx.clear();
    idx.resize(C);
    for (int i = 0; i < N; ++i) {
        int c = S[i]-'A';
        idx[c].insert(i);
    }
    ans = INF;
    dfs(0, 0, 0);
    cout << ans << '\n';
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
