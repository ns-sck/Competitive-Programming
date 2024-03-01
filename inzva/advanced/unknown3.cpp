#include <bits/stdc++.h>


#pragma GCC optimize("O3")
#pragma GCC target("sse4")


#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define lsb(i) i&(-i)
#define sz(i) (int)i.size()
#define PI 3.14159265
#define bla '\n'
 

typedef long long ll;
using namespace std;
const ll INF = 1e18L;
constexpr ll mod = ll(1e9) + 7;


ll t=1, cases = 0, n, q;


void solve(){
    cin >> n >> q;

    vector<vector<int>> bl(n + 1, vector<int>(30));

    for(int i = 1; i <= n; i++)
        cin >> bl[i][0];

    for(int i = 1; i < 30; i++) {
        for(int j = 1; j <= n; j++) {
            bl[j][i] = bl[bl[j][i - 1]][i - 1];
        }
    }

    while(q--) {
        int a, k; cin >> a >> k;

        for(int i = 0; i < 30; i++) {
            if((1 << i) & k)
                a = bl[a][i];
        }

        cout << a << bla;
    }
} 


int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    //cin>>t;
    for(; cases < t; cases++)solve();

    return 0;
}