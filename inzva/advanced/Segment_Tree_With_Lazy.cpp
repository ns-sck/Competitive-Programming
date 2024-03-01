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
#define UPP 100013ll
#define MOD (ll)1e9+7ll 


using namespace std;

ll arr[UPP];
ll st[4ll*UPP];
ll lazy[4ll*UPP];

void build(int v,int tl,int tr){
    if(tl>tr){
        return;
    }
    if(tl==tr){
        st[v] = arr[tl];
        return;
    }
    int tm = (tl + tr) / 2;
    build (2*v, tl, tm);
    build (2*v+1, tm+1, tr);
    st[v] = st[2*v] + st[2*v+1];
    return;
}

void update(int v,int tl,int tr,int l,int r,ll add){
    if(lazy[v]){
        st[v]+=(tr-tl+1)*lazy[v];
        if (2*v + 1 < 4ll * UPP) {
            lazy[2*v]+=lazy[v];
            lazy[2*v+1]+=lazy[v];
        }       
        lazy[v]=0;
    }
    if(tl>tr || tl>r || tr<l || l>r){
        return;
    }
    if(tl>=l && tr<=r){
        st[v]+=(tr-tl+1)*add;
        lazy[2*v]+=add;
        lazy[2*v+1]+=add;
        return;
    }
    int tm=(tl+tr)/2;    
    update(2*v,tl,tm,l,r,add);
    update(2*v+1,tm+1,tr,l,r,add);
    st[v]=st[2*v]+st[2*v+1];
    return;
}

ll query(int v,int tl,int tr,int l,int r){
    if(lazy[v]){
        st[v]+=(tr-tl+1)*lazy[v];
        if (2*v + 1< 4ll * UPP) {
            lazy[2*v]+=lazy[v];
            lazy[2*v+1]+=lazy[v];
        }
        lazy[v]=0;
    }
    if(tl>tr || tl>r || tr<l || l>r){
        return 0;
    }
    if(tl>=l && tr<=r){
        return st[v];
    }    
    int tm = (tl + tr) / 2;
    return query(2*v,tl,tm,l,r) + query(2*v+1,tm+1,tr,l,r);
}
