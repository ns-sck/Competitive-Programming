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
    
    if (N == 1) {
        cout << 1 << '\n';
        return;
    }

    priority_queue<pi> mx, mn;

    for (int i = 1; i <= N; ++i) {
        mx.push({i * (N - i + 1), i});
    }   

    for (int i = 2; i < N; ++i) {
        mn.push({(-i) * (N - i + 2), -i});
    }

    int in = N * (N + 1) / 2;
    int sub = in - (N * N / 2 + 1);
 
    while (1) {
        auto [x, y] = mx.top();
        mx.pop();

        auto [a, b] = mn.top();
        mn.pop();
        a = -a, b = -b;

        if (a < x) {
            mx.push({a, b});
            if ((a / b) < N) {
                mn.push({(a / b + 1) * (b), b});
                a = -a, b = -b;
            }
            if ((x / y) > 1) {
                mx.push({(x / y - 1) * (y), y});
            }
        } else {
            break;
        }
    }

    for (int i = 0; i < sub - 1; ++i) {
        auto [a, b] = mx.top();
        mx.pop();
        if (a / b > 1) {
            mx.push({(a / b - 1) * (b), b});
        }
    }
    cout << mx.top().first << '\n';
}

// 1  2  3  4  5  6  7  8  9
// 2  4  6  8 10 12 14 16 28
// 3  6  9 12 15 18 21 24 27
// 4  8 12 16 20 24 28 32 36
// 5 10 15 20 25 30 35 40 45
// 6 12 18 24 30 36 42 48 54
// 7 14 21 28 35 42 49 56 63
// 8 16 24 32 40 48 56 64 72
// 9 18 27 36 45 54 63 72 81

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}