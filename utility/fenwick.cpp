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

class BIT {
public:
    int N;
    vector<int> B1, B2;

    BIT(int size) : N(size), B1(size + 1, 0), B2(size + 1, 0) {}

    void add(vector<int>& b, int idx, int x) {
        for (; idx <= N; idx += idx & -idx)
            b[idx] += x;
    }

    void range_add(int l, int r, int x) {
        add(B1, l, x);
        add(B1, r + 1, -x);
        add(B2, l, x * (l - 1));
        add(B2, r + 1, -x * r);
    }

    int sum(const vector<int>& b, int idx) {
        int total = 0;
        for (; idx > 0; idx -= idx & -idx)
            total += b[idx];
        return total;
    }

    int prefix_sum(int idx) {
        return sum(B1, idx) * idx - sum(B2, idx);
    }

    int range_sum(int l, int r) {
        return prefix_sum(r) - prefix_sum(l - 1);
    }
};

void solve() {
    int N; cin >> N;
    BIT bit(N);
    for (int i = 1; i <= N; ++i) {
        int x; cin >> x;
        bit.range_add(i, i, x);
    }
    while (1) {
        vector<int> a(N);
        for (int i = 0; i < N; ++i) {
            a[i] = bit.range_sum(i + 1, i + 1);
        }
        int l, r, x;
        cin >> l >> r >> x;
        bit.range_add(l, r, x);
    }

    // cout << ans << '\n';
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
