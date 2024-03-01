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

vector<int> vec;

vector<int> lis;

int solve(){
    if((int)vec.size()==0){
        return 0;
    }
    vector<int> tut;
    vector<int> pre((int)vec.size(),-1);
    vector<int> tutkac((int)vec.size(),0);
    tut.pb(vec[0]);
    int don=1;
    for(int i=1;i<(int)vec.size();i++){
        auto it=lower_bound(tut.begin(),tut.end(),vec[i]);
        if(it==tut.end()){
            tut.pb(vec[i]);
            tutkac[don]=i;
            pre[i]=tutkac[don-1];
            don++;
        }
        else{
            int k=(int)(it-tut.begin());
            pre[i]= pre[tutkac[k]];
            tutkac[k]=i;
            *it=vec[i];
        }
    }
    stack<int>ss;
    for(int i=tutkac[don-1];i>=0;i=pre[i]){
        ss.push(vec[i]);
    }
    while(!ss.empty()) {
        lis.pb(ss.top());
        ss.pop();
    }
    cout<<endl;

    return don;
}


int main(){
    // vec.pb(2);
    // vec.pb(5);
    // vec.pb(3);
    // vec.pb(7);
    // vec.pb(11);
    // vec.pb(8);
    // vec.pb(10);
    // vec.pb(13);
    // int len = solve();
    // cout << len << "\n";
    // for(int cur : lis) {
    //     cout << cur << " ";
    // }
	// return 0;
}
