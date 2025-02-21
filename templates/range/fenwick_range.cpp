class BITR {
public:
  int N;
  vector<int> B1, B2;

  BITR(int size) : N(size), B1(size + 1, 0), B2(size + 1, 0) {}

  void add(vector<int>& b, int idx, int x) {
    for (; idx <= N; idx += idx & -idx) {
      b[idx] += x;
    }
  }

  void range_add(int l, int r, int x) {
    add(B1, l, x);
    add(B1, r + 1, -x);
    add(B2, l, x * (l - 1));
    add(B2, r + 1, -x * r);
  }

  int sum(const vector<int>& b, int idx) {
    int total = 0;
    for (; idx > 0; idx -= idx & -idx) {
      total += b[idx];
    }
    return total;
  }

  int prefix_sum(int idx) {
    return sum(B1, idx) * idx - sum(B2, idx);
  }

  int range_sum(int l, int r) {
    return prefix_sum(r) - prefix_sum(l - 1);
  }
};