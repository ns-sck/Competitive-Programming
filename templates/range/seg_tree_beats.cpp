#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

struct SegTreeBeats {
    struct Node {
        int64 sum;
        int64 max1, max2; int maxc;   // max value, 2nd max, count of max
        int64 min1, min2; int minc;   // min value, 2nd min, count of min
        int64 add;                    // lazy add
        Node() {
            sum = 0;
            max1 = LLONG_MIN/4; max2 = LLONG_MIN/4; maxc = 0;
            min1 = LLONG_MAX/4; min2 = LLONG_MAX/4; minc = 0;
            add = 0;
        }
    };

    int n;
    vector<Node> st;

    SegTreeBeats(int size = 0) { init(size); }

    void init(int size) {
        n = 1;
        while (n < size) n <<= 1;
        st.assign(2*n, Node());
    }

    // build from vector
    void build(const vector<int64>& a) {
        init((int)a.size());
        for (int i = 0; i < (int)a.size(); ++i) {
            Node &nd = st[n + i];
            nd.sum = a[i];
            nd.max1 = a[i]; nd.max2 = LLONG_MIN/4; nd.maxc = 1;
            nd.min1 = a[i]; nd.min2 = LLONG_MAX/4; nd.minc = 1;
            nd.add = 0;
        }
        for (int i = n - 1; i >= 1; --i) pull(i);
    }

private:
    // helper: merge children into parent
    void pull(int p) {
        const Node &L = st[p<<1], &R = st[p<<1|1];
        Node &X = st[p];
        X.sum = L.sum + R.sum;

        // max
        if (L.max1 > R.max1) {
            X.max1 = L.max1;
            X.maxc = L.maxc;
            X.max2 = max(L.max2, R.max1);
        } else if (L.max1 < R.max1) {
            X.max1 = R.max1;
            X.maxc = R.maxc;
            X.max2 = max(L.max1, R.max2);
        } else {
            X.max1 = L.max1;
            X.maxc = L.maxc + R.maxc;
            X.max2 = max(L.max2, R.max2);
        }

        // min
        if (L.min1 < R.min1) {
            X.min1 = L.min1;
            X.minc = L.minc;
            X.min2 = min(L.min2, R.min1);
        } else if (L.min1 > R.min1) {
            X.min1 = R.min1;
            X.minc = R.minc;
            X.min2 = min(L.min1, R.min2);
        } else {
            X.min1 = L.min1;
            X.minc = L.minc + R.minc;
            X.min2 = min(L.min2, R.min2);
        }

        X.add = 0;
    }

    // apply add to a node
    void apply_add(int p, int64 v, int len) {
        Node &nd = st[p];
        nd.sum += v * len;
        nd.max1 += v;
        if (nd.max2 > LLONG_MIN/4) nd.max2 += v;
        nd.min1 += v;
        if (nd.min2 < LLONG_MAX/4) nd.min2 += v;
        nd.add += v;
    }

    // apply chmin to node (assumes v < node.max1)
    void apply_chmin_node(int p, int64 v, int len) {
        Node &nd = st[p];
        nd.sum += (v - nd.max1) * nd.maxc;
        nd.max1 = v;
        if (nd.min1 > v) nd.min1 = v; // maintain consistency when range has single value
        // note: max2, min2 unchanged except when they conflict; handled by logic
    }

    // apply chmax to node (assumes v > node.min1)
    void apply_chmax_node(int p, int64 v, int len) {
        Node &nd = st[p];
        nd.sum += (v - nd.min1) * nd.minc;
        nd.min1 = v;
        if (nd.max1 < v) nd.max1 = v;
    }

    // push down pending operations from node p to children
    void push(int p, int l, int r) {
        if (p >= n) return; // leaf
        int mid = (l + r) >> 1;
        int ls = p<<1, rs = p<<1|1;
        Node &nd = st[p];
        if (nd.add != 0) {
            apply_add(ls, nd.add, mid - l + 1);
            apply_add(rs, nd.add, r - mid);
            nd.add = 0;
        }

        // propagate chmin for children if needed
        if (st[ls].max1 > nd.max1) apply_chmin_node(ls, nd.max1, mid - l + 1);
        if (st[rs].max1 > nd.max1) apply_chmin_node(rs, nd.max1, r - mid);

        // propagate chmax for children if needed
        if (st[ls].min1 < nd.min1) apply_chmax_node(ls, nd.min1, mid - l + 1);
        if (st[rs].min1 < nd.min1) apply_chmax_node(rs, nd.min1, r - mid);
    }

    // check if node range fully satisfies chmin with value x (i.e., max1 <= x -> nothing)
    bool all_le(int p, int64 x) { return st[p].max1 <= x; }
    // check if node range fully greater than x (i.e., max2 < x < max1 means we can apply chmin)
    bool can_chmin(int p, int64 x) { return st[p].max1 > x && st[p].max2 < x; }

    bool all_ge_min(int p, int64 x) { return st[p].min1 >= x; }
    bool can_chmax(int p, int64 x) { return st[p].min1 < x && st[p].min2 > x; }

public:
    // range add
    void range_add(int L, int R, int64 v) { range_add(1, 0, n-1, L, R, v); }
    // range chmin (a[i] = min(a[i], v))
    void range_chmin(int L, int R, int64 v) { range_chmin(1, 0, n-1, L, R, v); }
    // range chmax (a[i] = max(a[i], v))
    void range_chmax(int L, int R, int64 v) { range_chmax(1, 0, n-1, L, R, v); }
    // range sum query
    int64 range_sum(int L, int R) { return range_sum(1, 0, n-1, L, R); }

private:
    void range_add(int p, int l, int r, int L, int R, int64 v) {
        if (R < l || r < L) return;
        if (L <= l && r <= R) {
            apply_add(p, v, r - l + 1);
            return;
        }
        push(p, l, r);
        int mid = (l + r) >> 1;
        range_add(p<<1, l, mid, L, R, v);
        range_add(p<<1|1, mid+1, r, L, R, v);
        pull(p);
    }

    void range_chmin(int p, int l, int r, int L, int R, int64 x) {
        if (R < l || r < L || all_le(p, x)) return;
        if (L <= l && r <= R && can_chmin(p, x)) {
            apply_chmin_node(p, x, r - l + 1);
            return;
        }
        push(p, l, r);
        int mid = (l + r) >> 1;
        range_chmin(p<<1, l, mid, L, R, x);
        range_chmin(p<<1|1, mid+1, r, L, R, x);
        pull(p);
    }

    void range_chmax(int p, int l, int r, int L, int R, int64 x) {
        if (R < l || r < L || all_ge_min(p, x)) return;
        if (L <= l && r <= R && can_chmax(p, x)) {
            apply_chmax_node(p, x, r - l + 1);
            return;
        }
        push(p, l, r);
        int mid = (l + r) >> 1;
        range_chmax(p<<1, l, mid, L, R, x);
        range_chmax(p<<1|1, mid+1, r, L, R, x);
        pull(p);
    }

    int64 range_sum(int p, int l, int r, int L, int R) {
        if (R < l || r < L) return 0;
        if (L <= l && r <= R) return st[p].sum;
        push(p, l, r);
        int mid = (l + r) >> 1;
        return range_sum(p<<1, l, mid, L, R) + range_sum(p<<1|1, mid+1, r, L, R);
    }
};

// Example usage
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // small demo
    vector<int64> a = {5, 3, 8, 6, 2, 7};
    SegTreeBeats seg;
    seg.build(a);

    // do some operations:
    // decrease all values in [1,4] to at most 4 (chmin)
    seg.range_chmin(1, 4, 4);
    // increase all in [2,5] to at least 5 (chmax)
    seg.range_chmax(2, 5, 5);
    // add +3 to [0,2]
    seg.range_add(0, 2, 3);

    // query sum of whole array
    cout << "sum(0..5) = " << seg.range_sum(0, 5) << "\n";

    // query sum of subarray
    cout << "sum(1..3) = " << seg.range_sum(1, 3) << "\n";

    return 0;
}
