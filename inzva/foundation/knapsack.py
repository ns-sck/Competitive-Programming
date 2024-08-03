n = 5

profit = [8,5,6,4,5,5,9,8]
weights = [3,4,3,2,1,3,2,1]


len_row = len(profit)+1
len_col = n+1

dp = [[0 for i in range(len_col)] for i in range(len_row)]


for i in range(1,len_row):
    for j in range(1, len_col):
        if j - weights[i-1] >= 0:
            dp[i][j] = max(dp[i-1][j - weights[i-1]]+profit[i-1], dp[i-1][j])          
        else:
            dp[i][j] = dp[i-1][j]

print(dp)