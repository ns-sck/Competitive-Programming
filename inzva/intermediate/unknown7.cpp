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

int n, q;
vi v;
vi st;

int combine(int x, int y)
{
    return min(x, y);
}

// void print()
// {
    
// }

void build(int node, int segmentL, int segmentR)
{
    if(segmentL == segmentR)
    {
        int index = segmentL;
        st[node] = v[index];
        return;
    }
    
    int mid = (segmentL + segmentR) / 2;
    // 0,3
    //
    // (0,1) (2,3)
    build(2*node, segmentL, mid);
    build(2*node+1, mid+1, segmentR);
    st[node] = combine(st[2*node], st[2*node+1]);
}

int query(int node, int segmentL, int segmentR, int targetL, int targetR)
{
    if(segmentL == targetL && segmentR == targetR)
    {
        return st[node];
    }
    // 0,3
    // (1, 1) = (1, 1) left
    // (2, 2) = (2, 2) right
    // (1, 3) = (1, 1) + (2, 3) both left and right
    // (0,1) (2,3)
    int mid = (segmentL + segmentR) / 2;

    if(targetR <= mid)
    {
        // left
        return query(2*node, segmentL, mid, targetL, targetR);
    }
    else if(targetL >= mid+1)
    {
        // right
        return query(2*node+1, mid+1, segmentR, targetL, targetR);
    }
    else
    {
        int ansleft = query(2*node, segmentL, mid, targetL, mid);
        int ansRight = query(2*node+1, mid+1, segmentR, mid+1, targetR);
        return combine(ansleft, ansRight);
    }
}

void update(int node, int segmentL, int segmentR, int pos, int val)
{
    // cout << "update " << node << ' ' << val << endl; 
    if(segmentL == segmentR)
    {
        st[node] = val;
        return;
    }
    int mid = (segmentL + segmentR) / 2;
    if(pos <= mid)
    {
        // go left
        update(2*node, segmentL, mid, pos, val);
    }
    else
    {
        update(2*node+1, mid+1, segmentR, pos, val);
    }
    st[node] = combine(st[2*node], st[2*node+1]);
}

int32_t main()
{
    cin >> n >> q;
    v.resize(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    st.assign(4*n, 0);
    build(1, 0, n-1);
    while(q--)
    {
        int t;
        cin >> t;
        if(t == 2)
        {
            int l, r;
            cin >> l >> r;
            l--; r--;
            cout << query(1, 0, n-1, l, r) << endl;
        }
        else if(t == 1)
        {
            int pos, val;
            cin >> pos >> val;
            pos--;
            update(1, 0, n-1, pos, val);
        }
    }
}