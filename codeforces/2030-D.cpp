#include <bits/stdc++.h>
using namespace std;

template<typename... T>
void put(T&&... args) { ((cout << args << " "), ...); cout << '\n';}

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
const ld EPS = 1e-9; 

vpi st;
int N, Q;

void upd(int k, int x){
    k += N;
    st[k].first = x; 
    st[k].second = x; 
    k >>= 1;
    while(k >= 1){
        st[k].first = min(st[2*k].first, st[2*k+1].first);
        st[k].second = max(st[2*k].second, st[2*k+1].second);
        k >>= 1;
    }
}

ll qry(int a, int b){
    a += N, b += N;
    int ans = 0;
    while(a <= b){
        if (a&1) ans = max(ans, st[a++].second);
        if (~b&1) ans = max(ans, st[b--].second);
        a >>= 1, b >>= 1;
    }
    return ans;
}

ll qry2(int a, int b){
    a += N, b += N;
    int ans = INF;
    while(a <= b){
        if (a&1) ans = min(ans, st[a++].first);
        if (~b&1) ans = min(ans, st[b--].first);
        a >>= 1, b >>= 1;
    }
    return ans;
}

void solve() {
    cin >> N >> Q;
    st.clear();
    st.resize(2 * N);
    
    for (int i = 0; i < N; ++i) {
        int x; cin >> x;
        --x;
        upd(i, x);
    }


    string S; cin >> S;
    set<int> s = {0};

    for (int i = 1; i < N; ++i) {
        if (S[i] == 'R' && S[i-1] == 'L') s.insert(i);
    }

    bool b = 1;

    auto it = s.begin();

    while (it != s.end()) {
        auto it2 = it;
        ++it2;
        int l = *it, r = it2 == s.end() ? N - 1 : *it2 - 1;
        int mn = qry2(l, r), mx = qry(l, r);
        if (!(mn == l && mx == r)) {
            b = 0;
        }
        it = it2;
    }

   

    while (Q--) {
        int i; cin >> i;
        --i;
        if (S[i] == 'L') {
            if (i && S[i-1] == 'L') {
                s.insert(i);
            } 

            if (i < N && S[i+1] == 'R') {
                s.erase(i + 1);
            }
            S[i] = 'R';
        } else if (S[i] == 'R') {
            if (i < N && S[i+1] == 'R') {
                s.insert(i + 1);
            }
            if (i && S[i-1] == 'L') {
                s.erase(i);
            }
            S[i] = 'L';
        }

        auto it = s.begin();

        b = 1;

        while (it != s.end()) {
            auto it2 = it;
            ++it2;
            int l = *it, r = it2 == s.end() ? N - 1 : *it2 - 1;
            int mn = qry2(l, r), mx = qry(l, r);
            if (!(mn == l && mx == r)) {
                b = 0;
            }
            if (!b) break;
            it = it2;
        }
        if (b) put("YES");
        else put("NO");
    }

}

signed main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
