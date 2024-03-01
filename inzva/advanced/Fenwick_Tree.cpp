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

ll arr[UPP];
ll ft[UPP];
ll n;

void update(ll add,int pos){
    while(pos<=n){
        ft[pos]+=add;
        pos+=pos&(-pos);
    }
    return;
}

ll query(ll h){
    int don=0;
    while(h>0){
        don+=ft[h];
        h-=h&(-h);
    }
    return don;
}


