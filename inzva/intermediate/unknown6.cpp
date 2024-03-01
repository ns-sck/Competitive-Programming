#include <bits/stdc++.h>

#define loop(n) for(int $i = 0; $i < n; $i++)
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)

#define int ll

using namespace std;

typedef long long ll;   

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef tuple<int, int, int, int, int> iiiii;

typedef vector<bool> vb;

typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<iiii> viiii;
typedef vector<iiiii> viiiii;

typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef vector<viii> vviii;
typedef vector<viiii> vviiii;
typedef vector<viiiii> vviiiii;

template<typename T>
ostream & operator<<(ostream &os, const vector<T> &v)
{
    for(auto &x:v) cout << x << ' ';
    return os;
}

const int INF = 1e9+7;

int n, m;
vi st;
vi v;
void build(int x, int l, int r)
{
    if(l == r)
    {
        st[x] = v[l];
        return;
    }
    int mid = (l+r)/2;
    build(2*x, l, mid);
    build(2*x+1, mid+1, r);
    st[x] = st[2*x] + st[2*x+1];
}

int query(int x, int l, int r, int targetl, int targetr)
{
    if(l > targetr || r < targetl) return 0;
    if(l >= targetl && r <= targetr) return st[x];
    int mid = (l+r)/2;
    return query(2*x, l, mid, targetl, targetr) + query(2*x+1, mid+1, r, targetl, targetr);
}

void update(int x, int l, int r, int pos, int val)
{
    if(l > pos || r < pos) return;
    if(l == r)
    {
        st[x] = val;
        return;
    }
    int mid = (l+r)/2;
    update(2*x, l, mid, pos, val);
    update(2*x+1, mid+1, r, pos, val);
    st[x] = st[2*x] + st[2*x+1];
}

int32_t main()
{
    cin >> n >> m;
    v.resize(n);
    for(int &x:v) cin >> x;
    st.resize(4*n);
    build(1, 0, n-1);
    loop(m)
    {
        int x;
        cin >> x;
        if(x == 1)
        {
            int pos, val;
            cin >> pos >> val;
            pos--;
            update(1, 0, n-1, pos, val);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            l--, r--;
            cout << query(1, 0, n-1, l, r) << '\n';
        }
    }
}