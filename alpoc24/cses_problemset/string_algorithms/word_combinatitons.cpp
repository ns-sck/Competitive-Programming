#include <bits/stdc++.h>
using namespace std;

template<typename... T>
void put(T&&... args) { ((cout << args << " "), ...); cout << '\n';}

#define int long long
#define ll long long
#define pi pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpi vector<pi>
#define pb push_back
#define ar array
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

const ll MOD = 1e9+7;
const ll INF = 1e18;
const ll MAX = 5e3+2;

string S;
int dp[MAX];

struct node {
    node* nxt[26];
    char val;
    bool end = 0;
};

struct trie {
    node* root;
    trie() { root = new node(); }

    void insert(string s) {
        node* p = root;   
        for (int i = 0; i < s.size(); ++i) {
            int c = s[i] - 'a';
            if (!p->nxt[c]) p->nxt[c] = new node();
            p = p->nxt[c];
            if (i == s.size() - 1) p->end = 1; 
        }
    }

    void calc(int i) {
        int j = i;
        node* p = root;
        for (; i < S.size(); ++i) {
            char c = S[i] - 'a';
            p = p->nxt[c];
            if (!p) break;
            if (p->end) dp[i+1] = (dp[i+1] + dp[j]) % MOD;
        }
    }
};

void solve() {
    cin >> S;
    int K; cin >> K;
    int N = S.size();

    trie* t = new trie();

    while (K--) {
        string s; cin >> s;
        t->insert(s);
    }
    
    dp[0] = 1;
    for (int i = 0; i < N; ++i) {
        t->calc(i);
    }
    cout << dp[N] << '\n';
}

signed main () {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}
