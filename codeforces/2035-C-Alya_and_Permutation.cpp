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

    // 1 0 0 0 0 0 0
    // 0 1 1 1 1 1 1
    // 0 1 1 1 1 1 0
    // 0 0 0 0 0 0 1
    // 0 0 0 0 0 1 1

    // 1 0 0 0
    // 0 1 1 1
    // 0 1 1 0
    // 0 0 0 1
    // 0 0 1 1

    // 1 0 1 0 1 1 0
    // 0 1 0 1 0 0 1
    // 0 1 1 1 1 1 1

    // 1 0 0 0 0 0 1
    // 1 0 0 0 0 0 0
    // 0 0 0 0 0 0 1
    // 0 0 0 0 0 1 1

    // 1 0 0 1 1 1 1
    // 0 0 0 1 1 1 1
    // 1 0 0 0 0 0 0
    // 1 0 0 0 0 0 1

    int left = 0;
    for (int i = 0; i < 31; ++i) {
        if ((N >> i) & 1) left = i;
    }
    vi ans;
    if (N & 1) {
        put(N);
        if (__builtin_popcount(N) == 2) {
            int one = N;
            int two = N - 1;
            int three = 1;
            int four = 3;
            
            for (int i = 2; i < N - 1; ++i) {
                if (i == 3) continue;
                ans.pb(i);
            }

            ans.pb(four);
            ans.pb(three);
            ans.pb(two);
            ans.pb(one);
        } else {
            int one = N;
            int two = N & (~(1 << left));
            int three = 1 << left;
            int four = (1 << left) + 1;

            for (int i = 1; i < N; ++i) {
                if (i == two) continue;
                if (i == three) continue;
                if (i == four) continue;
                ans.pb(i);
            }
            ans.pb(four);
            ans.pb(three);
            ans.pb(two);
            ans.pb(one);
        }
    } else {
        put((1 << (left + 1)) - 1);
        if (__builtin_popcount(N) == 1) {
            int one = N;
            int two = N - 1;
            int three = N - 2;
            int four = 1;
            int five = 3;
            for (int i = 2; i < N - 2; ++i) {
                if (i == 3) continue;
                ans.pb(i);
            }
            ans.pb(five);
            ans.pb(four);
            ans.pb(three);
            ans.pb(two);
            ans.pb(one);
        } else {
            int x = 0;
            for (int i = 0; i < left; ++i) {
                if ((N >> i) & 1) continue;
                x |= (1 << i);
            }
            int one = N;
            int three = (1 << left) - 1;
            for (int i = 1; i < N; ++i) {
                if (i == x) continue;
                if (i == three) continue;
                ans.pb(i);
            }
            ans.pb(three);
            ans.pb(x);
            ans.pb(N);
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << ans[i] << " \n"[i == N - 1];
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