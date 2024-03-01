// author: erray
#include <bits/stdc++.h>

#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
#endif

using namespace std;

using F = array<int, 2>;
F operator+(F x, F y) {
  return {x[0] + y[0], x[1] + y[1]};
}
F& operator+=(F& x, F y) {
  x = x + y;
  return x;
}
F operator-(F x) {
  return {-x[0], -x[1]};
}
F operator-(F x, F y) {
  return x + -y;
}
F& operator-=(F& x, F y) {
  x = x - y;
  return x;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  const int MAX = *max_element(A.begin(), A.end());
  vector<vector<int>> find_first(MAX + 1, vector<int>(N));
  for (int m = 0; m <= MAX; ++m) {
    int cur = -1;
    for (int i = N - 1; i >= 0; --i) {
      find_first[m][i] = cur;
      if (A[i] > m) {
        cur = i;
      }
    }
  }
  auto C = [&](int l, int to) {
    if (to == -1) return 0;
    return to - l - 1;
  };
  auto U  = [&](int i, int x) {
    return C(i, find_first[x][i]);
  };
  int zero = 0;
  vector<int> first(N, -1), second(N, -1);
  for (int i = 0; i < N; ++i) {
    first[i] = find_first[A[i]][i];
    zero += C(i, first[i]);
    if (first[i] != -1) {
      second[i] = find_first[A[i]][first[i]];
    }
  } 
  vector<int> def(N);
  for (int i = 0; i < N; ++i) {
    def[i] = C(i, first[i]);
  }
  int ans = 0;
  { //smaller left
    vector<vector<int>> on(MAX + 1, vector<int>(N));
    for (int m = 0; m <= MAX; ++m) {
      vector<F> modify(N);
      F coeff{};      
      for (int i = 0; i < N; ++i) {
        coeff += modify[i];
        on[m][i] = coeff[1] * i + coeff[0];         
        if (A[i] < m) {
          F add{};
          add[1] = 1;
          add[0] = -1 - i - def[i];
          coeff += add;
          if (first[i] != -1) {
            modify[first[i]] -= add;
          }
        }    
      }
    }  
    vector<vector<int>> delta(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
      if (first[i] != -1) {
        int r = first[i];
        for (int l = 0; l < i; ++l) {
          if (A[l] < A[r] && A[i] >= A[l]) {
            delta[l][r] += C(i, second[i]) - C(i, first[i]);
          }
        }
      }
    }
    for (int l = 0; l < N; ++l) {
      for (int r = l + 1; r < N; ++r) {
        if (A[l] < A[r]) {
          int u = on[A[r]][l] - on[A[l]][l] + U(l, A[r]) + U(r, A[l]) - def[l] - def[r] + delta[l][r]; 
          ans = max(ans, u); 
        }                                
      }
    }
  }
  { //bigger left
    vector<vector<int>> delta(N, vector<int>(N));
    for (int l = 0; l < N; ++l) {
      vector<F> modify(N);
      F coeff{};
      for (int r = l + 1; r < N; ++r) {
        coeff += modify[r];
       if (A[l] > A[r]) {
          delta[l][r] = coeff[1] * r + coeff[0];
        } 
        if (A[r] < A[l]) {
          F add;
          add[1] = 1;
          add[0] = -1 - r - def[r];
          coeff += add;
          if (first[r] != -1) {
            modify[first[r]] -= add;
          }
        }  
      }     
    }
    for (int i = 0; i < N; ++i) {
      if (first[i] != -1) {
        int l = first[i];
        int block = -1;
        for (int r = l + 1; r < N; ++r) {
          if (A[l] > A[r] && A[r] <= A[i]) {
            if (block != -1) {
              delta[l][r] += block - l;
            } else {
              delta[l][r] += r - l;
            }
          }
          if (block == -1 && A[r] > A[i]) {
            block = r;
          }
        }
      }
    }
    for (int l = 0; l < N; ++l) {
      for (int r = l + 1; r < N; ++r) {
        if (A[l] > A[r]) {
          int to = find_first[A[r]][l];
          ans = max(ans, (to >= r || to == -1 ? C(l, r) : U(l, A[r])) + U(r, A[l]) - def[l] - def[r] + delta[l][r]); 
        }
      }
    }
  }               
  cout << ans + zero << '\n';
}