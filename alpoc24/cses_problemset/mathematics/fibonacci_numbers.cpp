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

map<int, int> mp;

int f(int x) {
    if (x == 0) return 0;
    if (x == 1) return 1;
    if (x == 2) return 1;
    if (x & 1) {
        int m = (x >> 1) + 1, n = x >> 1;
        int a = mp.count(m) ? mp[m] : f(m);
        a = (a * a) % MOD;
        int b = mp.count(n) ? mp[n] : f(n);
        b = (b * b) % MOD;
        return mp[x] = ((a + b) % MOD); 
    }
    int m = ((x >> 1) - 1), n = (x >> 1), k = ((x >> 1) + 1);
    int a = mp.count(m) ? mp[m] : f(m);
    int b = mp.count(n) ? mp[n] : f(n);
    int c = mp.count(k) ? mp[k] : f(k);
    return mp[x] = (((a * b) % MOD) + ((b * c) % MOD)) % MOD;
}

void solve() {
    int N; cin >> N;   
    
    cout << f(N) << '\n';
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