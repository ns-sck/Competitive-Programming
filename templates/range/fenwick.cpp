template <typename T>
class BIT {
  std::vector<T> bit;
  int n;
  BIT(T size) {
    n = size;
    bit.assign(n + 1, 0);
  }

  void update(int idx, T delta) {
    while (idx <= n) {
      bit[idx] += delta;
      idx += idx & -idx; 
    }
  }

  T query(int idx) {
    T sum = 0;
    while (idx > 0) {
      sum += bit[idx];
      idx -= idx & -idx;
    }
    return sum;
  }

  T range(int l, int r) {
    return query(r) - query(l - 1);
  }
};