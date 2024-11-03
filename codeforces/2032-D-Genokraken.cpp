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

int query(int a, int b) {
    // put('?', a, b);
    cout << "? " << a << ' ' << b << endl;
    int q; cin >> q;
    return q;
}

void solve() {
    int N; cin >> N;

    vi que, par(N);

    int cur = 2, i = 0;

    while (1) {
        int q = query(1, cur);
        assert(q != -1);
        if (q == 1) {
            par[cur] = 0;
            que.pb(cur++);
        } else {
            que.pb(cur);
            par[cur++] = 1;
            break;
        }
    }

    while (cur < N) {
        int q = query(que[i], cur);
        assert(q != -1);
        if (q == 0) {
            par[cur] = que[i++];
            que.pb(cur++);
        } else {
            i++;
        }
    }

    cout << "! ";
    for (int i = 1; i < N; ++i)
        cout << par[i] << ' ';
    cout << endl;
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