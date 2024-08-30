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
    pi p1, p2;
    cin >> p1.first >> p1.second >> p2.first >> p2.second;
    if (p1.first > p2.first) swap(p1, p2);
    if (p2.first > p1.second) {
        cout << 1 << '\n';
        return;
    } 
    if (p2.second <= p1.second) {
        cout << p2.second - p2.first + (p2.first > p1.first) + (p2.second < p1.second) << '\n';
        return;
    }
    cout << p1.second - p2.first + (p2.first > p1.first) + (p1.second < p2.second) << '\n';
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
