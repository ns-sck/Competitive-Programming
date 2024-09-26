#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace chrono;

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
const ll MAX = 1e3+1;

int dp[2][100001][1001];
int p[MAX];
int K;

ll lp[MAX+1];
vector<ll> pr;

void sieve() {
	for(ll i = 2; i < MAX; i++) {
		if(!lp[i]) {
			lp[i] = i;
			pr.push_back(i);
            if (pr.size() > MAX) break;
		}
		for(int j = 0; j < pr.size() && pr[j] <= lp[i] && i * pr[j] < MAX; j++) {
			lp[i * pr[j]] = pr[j];
		}
	}
}

int f(int i, bool b, int x) {
    if (i >= K) return b;

    auto &ref = dp[b][x][i];
    if (~ref) return ref;

    if (p[i] < x) return ref = f(i + 1, b, x);

    int a = p[i] - x + 2;

    if (b) {
        return ref = (a * f(i + 1, b, x)) % MOD;
    } 

    int y = f(i + 1, 1, x);
    int z = ((a - 1) * f(i + 1, b, x)) % MOD;
    return ref = (y + z) % MOD;
}

void solve() {
    cin >> K;

    sieve();
    
    int mx = 0;
    for (int i = 0; i < K; ++i) {
        cin >> p[i];
        mx = max(mx, p[i]);
    }

    int ans = 0;
    memset(dp, -1, sizeof(dp));

    for (int i = 1; i <= mx; ++i) {
        int a = (f(0, 0, i) * i) % MOD;
        ans = (ans + a) % MOD;
    }

    cout << ans << '\n';
}

signed main () {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    auto start = high_resolution_clock::now();

    int t = 1;
    // cin >> t;
    while (t--) solve();

    auto end = high_resolution_clock::now();
    
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Time taken: " << duration.count() << " ms" << '\n';

    return 0;
}