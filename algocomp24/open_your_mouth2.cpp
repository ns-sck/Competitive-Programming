#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define vi vector<int>
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
const int MOD = 1e9+7;

int32_t main() {
    ios;
    int n, q;
    cin >> n >> q;
    vi eat(n+1, 0);
    vi ch(n+1, 0);
    priority_queue<pii> pq;
    for (int i = 1; i <= n; ++i) {
        int a; cin >> a;
        if (i <= n/2)
            pq.push({(n-i+1) * (n-i+1) + a*a, i});
        else
            pq.push({i*i + a*a, i});
        ch[i] = a;
    }
    
    while(q--) {
        int qry; cin >> qry;
        if (qry == 1) {
            while (eat[pq.top().second] != 0) {
                auto p = pq.top(); pq.pop();
                int ind = p.second;
                int len = ch[ind] - eat[ind];
                ch[ind] = len;
                eat[ind] = 0;
                int sq = ind <= n/2 ? (n-ind+1) * (n-ind+1) + len*len : ind*ind + len*len;
                pq.push({sq, ind});
            }
            cout << pq.top().first << '\n';
        }
        else {
            int ind, dec; cin >> ind >> dec;
            eat[ind] += dec;
        }
    }

    return 0;
}
