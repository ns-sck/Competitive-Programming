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
    string S; cin >> S;
    int N = S.size();
    int Q; cin >> Q;
    
    set<int> s;
    for (int i = 0; i < N - 3; ++i) {
        if (S[i] == '1' && S[i+1] == '1' && S[i+2] == '0' && S[i+3] == '0') {
            s.insert(i);
        }
    }

    while (Q--) {
        int i, x;
        cin >> i >> x;
        --i;
        char c = x ? '1' : '0';
        if (S[i] == c) {
            if (s.size()) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
            continue;
        }
        S[i] = c;
        for (int j = max(0ll, i - 3); j <= min(N - 3, i); ++j) {
            if (s.find(j) != s.end()) {
                s.erase(j);
            }
            if (S[j] == '1' && S[j+1] == '1' && S[j+2] == '0' && S[j+3] == '0') {
                s.insert(j);
            }
        }
        if (s.size()) {
            cout << "YES\n";
        } else cout << "NO\n";
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