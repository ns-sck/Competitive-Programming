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

// 1 1 1 2 3 2 3 2 2 4 4 2 1 2 2

int N;
vi v, a;

void dfs(int i) {
    if (i == N - 1) {
        a[i] = INF;
        return;
    }

    dfs(i + 1);

    if (v[i+1] != v[i]) a[i] = i + 1;
    else a[i] = a[i+1];
}

void solve() {
    cin >> N;

    v.resize(N);
    a.assign(N, INF);

    for (int& x : v) cin >> x;
    dfs(0);

    int Q; cin >> Q;

    while (Q--) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        if (a[l] <= r) {
            put(l + 1, a[l] + 1);
        } else put("-1 -1");
    }
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