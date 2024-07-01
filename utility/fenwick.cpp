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

int N;
int fw[MAX];

void upd(int x, int v) {
    ++x; 
    for (; x < MAX; x += x & -x) fw[x] += v;
}

int get(int x) {
    ++x; 
    int ans = 0;
    for (; x > 0; x -= x & -x) ans += fw[x];
    return ans;
}

void solve() {
    cin >> N;
    vi v(N);
    for (int i = 0; i < N; ++i) {
        cin >> v[i];
    }

    int ans = 0;

    for (int i = N - 1; i >= 0; --i) {
        ans += get(v[i] - 1); 
        upd(v[i], 1);
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}
