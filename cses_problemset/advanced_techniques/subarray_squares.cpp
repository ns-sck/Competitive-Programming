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
    int N, K;
    cin >> N >> K;

    vi v(N), grp(K), st(K), sz(K);
    for (int& x : v) cin >> x;

    for (int i = 0; i < K; ++i) {
        st[i] = i;
        sz[i] = 1;
        int x = v[i];
        if (i == K-1) {
            while (++i < N) {
                x += v[i];
            }
            grp[K-1] = x;
            sz[K-1] = N-K+1;
        } else grp[i] = x;
    }

    if (K == 1) {
        cout << grp[0] * grp[0] << '\n';
        return;
    }

    priority_queue<int, vi, greater<>> pq;
    vector<bool> inpq(K, 0);

    if (grp[K-1] - v[K-1] >= grp[K-2] + v[K-1] && K != N) {
        pq.push(K-1);
        inpq[K-1] = 1;
    }
    
    while (pq.size()) {
        int i = pq.top();
        pq.pop();
        
        inpq[i] = 0;
        int x = st[i];
        grp[i-1] += v[x];
        grp[i] -= v[x];
        ++sz[i-1], --sz[i];
        st[i] = x+1;

        if (sz[i] > 1) {
            int give = v[st[i]];
            int diff0 = abs(grp[i] - grp[i-1]);
            int diff1 = abs(grp[i] - give - grp[i-1] - give);
            if (diff1 <= diff0) {
                pq.push(i);
                inpq[i] = 1;
            }
        }

        if (i < K-1 && sz[i+1] > 1) {
            int give = v[st[i+1]];
            int diff0 = abs(grp[i+1] - grp[i]);
            int diff1 = abs(grp[i+1] - give - grp[i] - give);
            if (diff1 <= diff0 && !inpq[i+1]) {
                pq.push(i+1);
                inpq[i+1] = 1;
            }
        } 

        if (i > 1) {
            int give = v[st[i-1]];
            int diff0 = abs(grp[i-1] - grp[i-2]);
            int diff1 = abs(grp[i-1] - give - grp[i-2] - give);
            if (diff1 <= diff0) {
                pq.push(i-1);
                inpq[i-1] = 1;
            }
        }
    }

    int ans = 0;
    
    for (int i = 0; i < K; ++i) {
        ans += grp[i] * grp[i];
    }

    cout << ans << '\n';
}

signed main () {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}
