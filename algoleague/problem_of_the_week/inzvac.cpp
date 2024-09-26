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
    string S; cin >> S;

    map<char, int> mp;

    for (int i = 0; i < N; ++i) {
        if (S[i] == 'i') {
            ++mp['i'];
        } else if (S[i] == 'n') {
            mp['n'] = (mp['n'] + mp['i']) % MOD;
        } else if (S[i] == 'z') {
            mp['z'] = (mp['z'] + mp['n']) % MOD;
        } else if (S[i] == 'v') {
            mp['v'] = (mp['v'] + mp['z']) % MOD;
        } else if (S[i] == 'a') {
            mp['a'] = (mp['a'] + mp['v']) % MOD;
        } else if (S[i] == 'c') {
            mp['c'] = (mp['c'] + mp['a']) % MOD;
        }
    }   

    cout << mp['c'] << '\n'; 
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