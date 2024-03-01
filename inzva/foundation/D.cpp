#include<bits/stdc++.h>
#define inf (ll)1e17
#define ll long long
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define fri(b) freopen(b,"r",stdin)
#define fro(b) freopen(b,"w",stdout)
#define bassifir(a) __builtin_clz(a)
#define sonsifir(a) __builtin_ctz(a)
#define birsay(a) __builtin_popcount(a)
#define UPP 200013ll
#define MOD ((ll)1e9+7ll)


using namespace std;

vector < pair < ll , pair < int,int > > > edges;

int par[UPP];
int mem[UPP];
ll cost;
int n,m,k;

int find (int x) {
    if(x == par[x]) {
        return x;
    }
	par[x] = find (par[x]);
	return par[x];
    // return par[x] = find(par[x]);
}


void uni (int x, int y) {
    x = find(x);
    y = find(y);
    if(x != y) {
        if(mem[x] < mem[y]) {
            swap(x,y);
        }
        par[y] = x;
        mem[x] += mem[y];
    }
}

void kruskal() {

    sort(edges.begin(),edges.end());

    for(int i = 1; i <= n; i++) {
        par[i] = i;
        mem[i] = 1;
    }

    for(pair < ll,pair < int,int > > pp : edges) {
        int a,b;
        ll w;
        a = pp.second.first;
        b = pp.second.second;
        w = pp.first;
        if(find(a) != find(b)) {
            uni(a,b);
            cost += w;
        }
		else if (w < 0) {
			cost += w;
		}
    }
}


int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);
	cout.tie(0);
	// fri("contestgir.txt");
	// fro("contestcik.txt");

	
	cin >> n >> m;
	assert (2 <= n && n <= (int)2e5);
	assert (n-1 <= m && m <= (int)2e5);
	ll ans = 0ll;

	for (int i = 1; i <= m; i++) {
		int a,b;
		ll w;
		cin >> a >> b >> w;
		ans += w;
		assert (1 <= a && a <= n && 1 <= b && b <= n);
		assert (-(ll)1e9 <= w && w <= (ll)1e9);
		edges.pb(mp(w,mp(a,b)));
		// edges.pb(mp(w,mp(b,a)));
	}
	kruskal();
	ans -= cost;
	cout << ans;

	

	return 0;
}