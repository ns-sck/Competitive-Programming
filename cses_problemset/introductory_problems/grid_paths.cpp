    #include <bits/stdc++.h>
    using namespace std;

    bool b[7][7];
    int ans = 0;
    string s;
    bool control (int i, int j)
    {
        return (i >= 0 && i < 7 && j >= 0 && j < 7 && !b[i][j]);
    }
    void dfs(int st, int i, int j)
    {   
        if (i == 6 && j == 0) {
            if (st == 48)
                ++ans;
            return;
        }
        b[i][j] = 1;

        if (s[st] == 'L' || s[st] == '?') {
            if (j && !b[i][j-1])
                if (!(!control(i, j-2) && control(i+1, j-1) && control(i-1, j-1)))
                    dfs(st+1, i, j-1);
        }
        if (s[st] == 'R' || s[st] == '?') {
            if (j < 6 && !b[i][j+1])
                if (!(!control(i, j+2) && control(i+1, j+1) && control(i-1, j+1)))
                    dfs(st+1, i, j+1);
        }
        if (s[st] == 'D' || s[st] == '?') {
            if (i < 6 && !b[i+1][j])
                if (!(!control(i+2, j) && control(i+1, j-1) && control(i+1, j+1)))
                    dfs(st+1, i+1, j);
        }
        if (s[st] == 'U' || s[st] == '?') {
            if (i && !b[i-1][j]) 
                if (!(!control(i-2, j) && control(i-1, j-1) && control(i-1, j+1)))
                    dfs(st+1, i-1, j);
        }

        b[i][j] = 0;
    }
    int32_t main() {
        cin >> s;
        dfs(0, 0, 0);
        cout << ans << '\n';
        return 0;
    }
