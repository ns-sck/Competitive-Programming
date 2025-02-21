#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,
             tree_order_statistics_node_update>;

#define ll long long
#define pi pair<int, int>
#define vi vector<int>
#define vii vector<vector<int>>
#define vpi vector<pi>
#define pb push_back
#define ar array
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
template<typename... T>
void see(T&... args) { ((cin >> args), ...);}
const ll MOD = 1e9+7;
const ll INF = 1e18;
const ll MAX = 2e5+1;
const long double EPS = 1e-9; 
#define seea(a,x,y) for(int i=x;i<y;i++){cin>>a[i];}
template<typename... T>
void putl(T&&... args) { ((cout << args << " "), ...); cout<<'\n';}
#define rep(i,a,b) for (int i=a; i<b; ++i)
void solve(){
    oset<ar<int, 2>> s;
    int n,k; see(n,k);
    int a[n+1]; seea(a,1,n+1);
    rep(i,1,n+1){
        s.insert({a[i], i});
    }
    while(k--){
        char x; int y,z; see(x,y,z);
        if (x=='?'){
            putl(s.order_of_key({z+1}) - s.order_of_key({y}));
        }
        else{
            s.erase(s.find_by_order(s.order_of_key({a[y]})));
            a[y] = z;
            s.insert({z, y});
        }
    }
}    
int main () {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
