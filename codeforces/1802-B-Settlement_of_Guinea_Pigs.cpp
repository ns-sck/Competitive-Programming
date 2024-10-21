#include <bits/stdc++.h>
using namespace std;

template<typename... T>
void put(T&&... args) { ((cout << args << " "), ...); cout << '\n';}

#define int long long
#define ll long long
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
    vi v(N);

    for (int i = 0; i < N; ++i) {
        cin >> v[i];
    }

    int e = 0, ans = 0, c = 0;

    for (int i = 0; i < N; ++i) {
        if (v[i] == 1) {
            ++c;
            if (e) --e;
            else ++ans;
        } else {
            int a = c / 2 + 1;
            if (c == 0) a = 0;
            e = ans - a;
        }
    }

    put(ans);
}

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}