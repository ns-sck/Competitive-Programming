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


ll t=1, cases = 0, n, m;
vector<vector<pair<int, int>>> comp;


class Node {
public:
    Node* next[5];

    Node() {
        for(int i = 0; i < 5; i++) {
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

    void insert(string &s) {
        Node* curr = root;
        for(char bit : s) {
            if(curr -> next[bit - '0'] == nullptr) {
                curr -> next[bit - '0'] = new Node();
            }
            curr = curr -> next[bit - '0'];
        }
    }

    string query(string &s) {
        Node* curr = root;
        string ans = "";
        for(char curbit : s) {
            for(int j = 0; j < 5; j++) {
                if(curr -> next[comp[curbit - '0'][j].nd] != nullptr) {
                    ans += comp[curbit - '0'][j].st + '0';
                    curr = curr -> next[comp[curbit - '0'][j].nd];
                    break;
                }
            }
        }
        return ans; 
    }
};


void solve(){
    cin >> n >> m;

    string ans = "0";

    comp.resize(5, vector<pair<int, int>>(5));

    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++) {
            cin >> comp[i][j].st;
            comp[i][j].nd = j;
        }

    for(int i = 0; i < 5; i++)
        sort(comp[i].rbegin(), comp[i].rend());

    Trie* trie = new Trie();

    vector<string> ar(n);
    for(int i = 0; i < n; i++) {
        cin >> ar[i];
        trie -> insert(ar[i]);
    }

    for(int i = 0; i < n; i++)
        ans = max(ans, trie -> query(ar[i]));

    cout << ans << bl;
} 


int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    //cin>>t;
    for(; cases < t; cases++)solve();

    return 0;
}