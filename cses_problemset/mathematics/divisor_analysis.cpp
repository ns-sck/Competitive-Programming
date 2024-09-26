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
 
int N, b[MAX], p[MAX];
 
int fp(int base, int exp) {
    int rval = 1LL;
    while (exp) {
        if (exp & 1) {
            rval *= base;
            rval %= MOD;
        }
        base *= base;
        base %= MOD;
        exp >>= 1;
    }
    return rval;
}
 
long long inv(long long x){
	return fp(x, MOD-2);
}
 
int find(int base, int pw) {
    if (pw == 0) return 1;
    if (pw == 1) return base;
    int x = 0;
    if (pw & 1) x += fp(base, pw);
    int y = find(base, pw >> 1);
    x = (x + y * ((fp(base, pw >> 1) + 1) % MOD)) % MOD;
    return x % MOD;    
}
 
int dfs(int idx) {
    if (idx == N) return 1;
    int x = (find(b[idx], p[idx]) + 1) % MOD;
    return (x * dfs(idx + 1)) % MOD;
}
 
// 60 -> 1 2 3 4 5 6 10 12 15 20 30 60
void solve() {
    
    cin >> N;
    auto mult = [&](int x, int y) {
        return (1LL * x * y) % MOD;
    };
 
    auto add = [&](int x, int y) {
        return (x + y) % MOD;
    };
 
    int num = 1, sum = 0, pr = 1, num2 = 1;
    for (int i = 0; i < N; ++i) {
        cin >> b[i] >> p[i];
        num = mult(num, p[i] + 1);
 
        pr = fp(pr, p[i] + 1) * fp(fp(b[i], p[i] * (p[i] + 1) / 2), num2) % MOD;
        num2 = (p[i] + 1) * num2 % (MOD - 1);
    }
 
    sum = dfs(0);
    put(num, sum, pr);
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