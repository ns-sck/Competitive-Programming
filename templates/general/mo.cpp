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

int bsz;
struct Query {
    int l, r, idx;
    bool operator<(const Query& other) const {
        if (l / bsz != other.l / bsz)
            return l / bsz < other.l / bsz;
        return r < other.r;
    }
};
map<int, int> freq;

void solve() {
    int N, Q;
    cin >> N >> Q;
    vi v(N);
    for (auto& x : v) cin >> x;
    vector<Query> queries(Q);
    bsz = sqrt((double)N) + 1;
    for (int i = 0; i < Q; ++i) {
        cin >> queries[i].l >> queries[i].r;
        --queries[i].l, --queries[i].r;
        queries[i].idx = i;
    }
    sort(all(queries));

    int dist = 0, lf = 0, r = -1;
    vi ans(Q);
    int mx = 0;
    for (const auto& q : queries) {
        while (lf > q.l) {
            --lf;
            if (++freq[v[lf]] == 1) {
                mx = max(v[lf], mx);
            }
        }
        while (r < q.r) {
            ++r;
            if (++freq[v[r]] == 1) {
                mx = max(v[r], mx);
            }
        }
        while (lf < q.l) {
            if (--freq[v[lf]] == 0) {
                freq.erase(v[lf]);
                if (v[lf] < mx) continue;
                if (freq.size()) {
                    auto it = freq.end();
                    --it;
                    mx = it->first;
                }
            }
            ++lf;
        }
        while (r > q.r) {
            if (--freq[v[r]] == 0) {
                freq.erase(v[r]);
                if (freq.size()) {
                    auto it = freq.end();
                    --it;
                    mx = it->first;
                }
            }
            --r;
        }
        ans[q.idx] = mx;
    }
    for (int i = 0; i < Q; ++i) cout << ans[i] << '\n';
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}
