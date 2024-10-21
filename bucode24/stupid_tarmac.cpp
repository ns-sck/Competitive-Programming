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
const ll MAX = 2e5+1;

vector<int> f(int V, vector<set<int>>& adj) {
    vector<int> in_degree(V, 0);
    for (int u = 0; u < V; u++) {
        for (int v : adj[u]) {
            in_degree[v]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }
    vector<int> top_order;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        top_order.push_back(u);
        for (int v : adj[u]) {
            if (--in_degree[v] == 0) {
                q.push(v);
            }
        }
    }
    if (top_order.size() != V) {
        cout << "There exists a cycle in the graph" << endl;
    }
    return top_order;
}

void solve() {
    int N, M;
    cin >> N >> M;
    
    vector<set<int>> adj(N);

    while (M--) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].insert(v);
    }

    vi top = f(N, adj);
    vi pos(N);

    for (int i = 0; i < N; ++i) {
        pos[top[i]] = i;
    }

    int ans = 0;

    for (int i = 0; i < N; ++i) {
        bool ok = 0;
        vi q;
        int j = 0;
        q = {i};

        while (j < q.size()) {
            int u = q[j++];

            int a = INF, b = -1;
            for (auto v : adj[u]) {
                if (pos[v] < a) {
                    a = pos[v];
                    b = v;
                }
            }

            if (~b) {
                q.pb(b);
                adj[u].erase(b);
                ok = 1;
            }
        }
        ans += ok;
    }

    put(ans);

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