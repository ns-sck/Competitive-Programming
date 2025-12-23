#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  vector<int> v(3);
  for (int i = 0; i < 3 * n; ++i) {
    v[s[i] - 'A']++;
  }
  bool A = 0, B = 0, C = 0;
  int cnt = 0;
  int targeta = 0, targetb = 0, targetc = 0;
  if (v[0] >= n) {A = 1; targeta = v[0] - n; cnt++;}
  if (v[1] >= n) {B = 1; targetb = v[1] - n; cnt++;}
  if (v[2] >= n) {C = 1; targetc = v[2] - n; cnt++;}
  if (cnt == 3) {
    cout << 0;
  }
  else if (cnt == 2) {
    if (!A) {
      int l = 0, r = 1;
      int currb = 0, currc = 0;
      if (s[0] == 'B') currb++;
      if (s[0] == 'C') currc++;
      while (r >= l && r <= 3 * n) {
        if (currb == targetb && currc == targetc) {
          cout << 1 << '\n';
          cout << l + 1 << ' ' << r  << ' ' << "A\n";
          return;
        }
        else if (currb > targetb || currc > targetc) {
          while (currb > targetb || currc > targetc) {
            if (s[l] == 'B') currb--;
            else if (s[l] == 'C') currc--;
            l++;
          }
        }
        else {
          if (s[r] == 'B') currb++;
          if (s[r] == 'C') currc++;
          r++;
        }
      }
    }
    else if (!B) {
      int l = 0, r = 1;
      int curra = 0, currc = 0;
      if (s[0] == 'A') curra++;
      if (s[0] == 'C') currc++;
      while (r >= l && r <= 3 * n) {
        if (curra == targeta && currc == targetc) {
          cout << 1 << '\n';
          cout << l + 1 << ' ' << r  << ' ' << "B\n";
          return;
        }
        else if (curra > targeta || currc > targetc) {
          while (curra > targeta || currc > targetc) {
            if (s[l] == 'A') curra--;
            else if (s[l] == 'C') currc--;
            l++;
          }
        }
        else {
          if (s[r] == 'A') curra++;
          if (s[r] == 'C') currc++;
          r++;
        }
      }
    }
    else if (!C) {
      int l = 0, r = 1;
      int curra = 0, currb = 0;
      if (s[0] == 'A') curra++;
      if (s[0] == 'B') currb++;
      while (r >= l && r <= 3 * n) {
        if (curra == targeta && currb == targetb) {
          cout << 1 << '\n';
          debug(curra, currb);
          debug(l, r);
          cout << l + 1 << ' ' << r  << ' ' << "C\n";
          return;
        }
        else if (curra > targeta || currb > targetb) {
          while (curra > targeta || currb > targetb) {
            if (s[l] == 'A') curra--;
            else if (s[l] == 'B') currb--;
            l++;
          }
        }
        else {
          if (s[r] == 'A') curra++;
          if (s[r] == 'B') currb++;
          r++;
        }
      }
    }
  }
  else if (cnt == 1) {
    cout << 2 << '\n';
    int l = 0, r = 1;
    char c = 'D';
    if (!A) {
      int currb = 0, currc = 0;
      int needed = n - v[0];
      if (s[l] == 'B') currb++;
      if (s[l] == 'C') currc++;
      while (r >= l && r <= 3 * n) {
        if (currb + currc == needed) {
          cout << l + 1 << ' ' << r  << " A\n";
          l = r + 1;
          r = l + 1;
          c = 'A';
          v[1] -= currb;
          v[2] -= currc;
          break;
        }
        else {
          if (s[r] == 'B') currb++;
          if (s[r] == 'C') currc++;
          r++;
        }
      }
    }
    if (!B) {
      int curra = 0, currc = 0;
      int needed = n - v[1];
      if (c == 'D') {
        if (s[l] == 'A') curra++;
        if (s[l] == 'C') currc++;
        while (r >= l && r <= 3 * n) {
          if (curra + currc == needed) {
            cout << l + 1 << ' ' << r  << " B\n";
            l = r + 1;
            r = l + 1;
            c = 'B';
            v[0] -= curra;
            v[2] -= currc;
            break;
          }
          else {
            if (s[r] == 'A') curra++;
            if (s[r] == 'C') currc++;
            r++;
          }
        }
      }
      else {
        if (s[l] == 'A') curra++;
        if (s[l] == 'C') currc++;
        while (r >= l && r <= 3 * n) {
          if (curra) {
            if (s[l] == 'A') curra--;
            if (s[l] == 'C') currc--;
            l++;
          }
          else if (currc == needed) {
            cout << l + 1 << ' ' << r  << " B\n";
            l = r + 1;
            r = l + 1;
            v[2] -= currc;
            break;
          }
          else {
            if (s[r] == 'A') curra++;
            if (s[r] == 'C') currc++;
            r++;
          }
        }
      }
    }
    if (!C) {
      int curra = 0, currb = 0;
      int needed = n - v[2];
      if (c == 'D') {
        if (s[l] == 'A') curra++;
        if (s[l] == 'B') currb++;
        while (r >= l && r <= 3 * n) {
          if (curra + currb == needed) {
            cout << l + 1 << ' ' << r  << " C\n";
            l = r + 1;
            r = l + 1;
            v[0] -= curra;
            v[1] -= currb;
            break;
          }
          else {
            if (s[r] == 'A') curra++;
            if (s[r] == 'B') currb++;
            r++;
          }
        }
      }
      else if (c == 'A') {
        if (s[l] == 'A') curra++;
        if (s[l] == 'B') currb++;
        while (r >= l && r <= 3 * n) {
          if (curra) {
            if (s[l] == 'A') curra--;
            if (s[l] == 'B') currb--;
            l++;
          }
          else if (currb == needed) {
            cout << l + 1 << ' ' << r  << " C\n";
            l = r + 1;
            r = l + 1;
            v[2] -= currb;
            break;
          }
          else {
            if (s[r] == 'A') curra++;
            if (s[r] == 'B') currb++;
            r++;
          }
        }
      }
      else { // B
        if (s[l] == 'A') curra++;
        if (s[l] == 'B') currb++;
        while (r >= l && r <= 3 * n) {
          if (currb) {
            if (s[l] == 'A') curra--;
            if (s[l] == 'B') currb--;
            l++;
          }
          else if (curra == needed) {
            cout << l + 1 << ' ' << r  << " C\n";
            l = r + 1;
            r = l + 1;
            break;
          }
          else {
            if (s[r] == 'A') curra++;
            if (s[r] == 'B') currb++;
            r++;
          }
        }
      }
    }
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) solve();
  return 0;
}