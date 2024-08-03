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
	int N; cin >> N;
    vpi v(N);
    for (int i = 0; i < N; ++i)
        cin >> v[i].first >> v[i].second, v[i].second = -v[i].second;
    
    sort(all(v));
    priority_queue<int, vi, greater<>> pq;
    int c = 0, ans = 0, mx = 0;
    for (int i = 0; i < N; ++i) {
        int a = v[i].first, b = -v[i].second;
        if (mx >= a) continue;
        ans += b;
        ++c;
        pq.push(a);
        mx = max(mx, c);
        while (pq.size() && mx >= pq.top()) {
            --c;
            pq.pop();
        }
    }
    cout << ans << '\n';
    // a --> 1, 1, 2, 2, 5,
    // b --> 2, 3, 8, 9, 4

    // a --> 1, 1, 2, 3, 3, 3
    // b --> 2, 4, 3, 4, 4, 5
}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
