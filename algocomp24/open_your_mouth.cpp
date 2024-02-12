#include <bits/stdc++.h>
using namespace std;
#define int long long
void build(vector<int>& arr, vector<int>& tree, int current_node, int start, int end) {
    if (start == end) {
        tree[current_node] = arr[start];
    } else {
        int mid = (start + end) / 2;
        build(arr, tree, 2 * current_node + 1, start, mid);
        build(arr, tree, 2 * current_node + 2, mid + 1, end);
        tree[current_node] = max(tree[2 * current_node + 1], tree[2 * current_node + 2]);
    }
}

void update(vector<int>& arr, vector<int>& tree, int current_node, int start, int end, int index, int new_value) {
    if (start == end) {
        arr[index] = new_value;
        tree[current_node] = new_value;
    } else {
        int mid = (start + end) / 2;
        if (start <= index && index <= mid) {
            update(arr, tree, 2 * current_node + 1, start, mid, index, new_value);
        } else {
            update(arr, tree, 2 * current_node + 2, mid + 1, end, index, new_value);
        }
        tree[current_node] = max(tree[2 * current_node + 1], tree[2 * current_node + 2]);
    }
}

int query_max(vector<int>& tree, int current_node, int start, int end, int query_start, int query_end) {
    if (query_end < start || query_start > end) {
        return INT_MIN;
    }
    if (query_start <= start && query_end >= end) {
        return tree[current_node];
    }
    int mid = (start + end) / 2;
    int left_max = query_max(tree, 2 * current_node + 1, start, mid, query_start, query_end);
    int right_max = query_max(tree, 2 * current_node + 2, mid + 1, end, query_start, query_end);
    return max(left_max, right_max);
}

int32_t main() {
    int n, q;
    cin >> n >> q;
    vector<int> v(n, 0);
    vector<int> squares(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    for (int i = 0; i < n / 2; ++i) {
        squares[i] = (n - i) * (n - i) + v[i] * v[i];
    }
    for (int i = n / 2; i < n; ++i) {
        squares[i] = (i + 1) * (i + 1) + v[i] * v[i];
    }
    int tree_size = 1;
    while (tree_size < n) {
        tree_size *= 2;
    }
    tree_size *= 2;

    vector<int> tree(tree_size);
    build(squares, tree, 0, 0, n - 1);
    
    while (q--) {
        int a;
        cin >> a;
        if (a == 1) {
            cout << query_max(tree, 0, 0, n - 1, 0, n - 1) << '\n';
        } else {
            int b, c;
            cin >> b >> c;
            v[b - 1] -= c;
            if (b > n / 2)
                squares[b - 1] = b * b + v[b - 1] * v[b - 1];
            else 
                squares[b - 1] = (n - b + 1) * (n - b + 1) + v[b - 1] * v[b - 1];
            update(squares, tree, 0, 0, n - 1, b - 1, squares[b - 1]);
        }
    }

    return 0;
}
