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
#define bl '\n'
 

typedef long long ll;
using namespace std;
const ll INF = 1e18L;
constexpr ll mod = ll(1e9) + 7;


ll t=1, cases = 0, n, k;


class Node {
public:
    int count;
    Node* next[2];

    Node() {
        count = 1;
        for(int i = 0; i < 2; i++) {
            next[i] = nullptr;
        }
    }
};


class Trie {
public:
    Node* root;

    Trie() {
        root = new Node();
    }

    void insert(ll x) {
        Node* curr = root;
        for(ll i = 30; i >= 0; i--) {
            bool bit = (1 << i) & x;
            if(curr->next[bit] == nullptr) {
                curr->next[bit] = new Node();
            } else {
                curr->next[bit]->count++;
            }
            curr = curr->next[bit];
        }
    }

    ll query(ll x) {
        Node* curr = root;
        ll ans = 0;
        for(int i = 30; i >= 0; i--) {
            if(curr == nullptr) {
                break;
            }

            bool bit = (1 << i) & x;
            bool is_k = (1 << i) & k;

            if(is_k) {
                if(curr -> next[bit] != nullptr) {
                    ans += curr->next[bit] -> count;
                }

                curr = curr -> next[1 - bit];
            } else {
                curr = curr -> next[bit];
            }
        }
        return ans;
    }
};


void solve(){
    ll ans = 0;

    cin >> n >> k;

    Trie* trie = new Trie();

    for(int i = 0; i < n; i++) {
        ll x; cin >> x;
        ans += trie -> query(x);
        trie->insert(x);
    }
    
    cout << ans;
} 


int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    //cin>>t;
    for(; cases < t; cases++)solve();

    return 0;
}