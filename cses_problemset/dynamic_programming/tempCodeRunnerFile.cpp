]-prfx[j+1]-dp[j+1][i][1]+v[j]);
                    dp[j][i][1] = max(dp[j][i-1][1], dp[j+1][i][1]);
                }