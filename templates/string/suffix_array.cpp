// without '$', it sorts all cyclic shifts
// with, it sorts all suffixes
vector<int> sort_cyclic(string s) {
  s += '$';
  int n = s.size();
  const int alp = 256;
  vector<int> p(n), c(n), cnt(max(alp, n));
  for (int i = 0; i < n; ++i) {
    ++cnt[s[i]];
  }
  for (int i = 1; i < alp; ++i) {
    cnt[i] += cnt[i - 1];
  }
  for (int i = 0; i < n; ++i) {
    p[--cnt[s[i]]] = i;
  }
  c[p[0]] = 0;
  int j = 1; 
  for (int i = 1; i < n; ++i) {
    if (s[p[i]] != s[p[i - 1]]) {
      ++j;
    }
    c[p[i]] = j - 1;
  }
  vector<int> pn(n), cn(n);
  for (int h = 0; (1 << h) < n; ++h) {
    for (int i = 0; i < n; ++i) {
      pn[i] = p[i] - (1 << h);
      if (pn[i] < 0) {
        pn[i] += n;
      }
    }
    fill(cnt.begin(), cnt.begin() + j, 0);
    for (int i = 0; i < n; i++) {
      cnt[c[pn[i]]]++;
    }
    for (int i = 1; i < j; i++) {
      cnt[i] += cnt[i-1];
    }
    for (int i = n-1; i >= 0; i--) {
      p[--cnt[c[pn[i]]]] = pn[i];
    }
    cn[p[0]] = 0;
    j = 1;
    for (int i = 1; i < n; i++) {
      pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
      pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
      if (cur != prev) {
        ++j;
      }
      cn[p[i]] = j - 1;
    }
    c.swap(cn);
  }
  return p;
}