#include<bits/stdc++.h>
#define inf INT_MAX
#define ll long long
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define fri(b) freopen(b,"r",stdin)
#define fro(b) freopen(b,"w",stdout)
#define bassifir(a) __builtin_clz(a)
#define sonsifir(a) __builtin_ctz(a)
#define birsay(a) __builtin_popcount(a)
#define UPP 100013
#define MOD (ll)1e9+7ll 


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
    return par[x] = find(par[x]);
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
    }
}
