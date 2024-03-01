first_name = 'winterva'
second_name = 'inzva'

dp =[ [0 for i in range(len(first_name)+1)] for j in range(len(second_name)+1)]

for i in range(1,len(second_name)+1):
    for j in range(1,len(first_name)+1):
        if (first_name[j-1] == second_name[i-1]):
            dp[i][j] = dp[i-1][j-1]+1
        else:
            dp[i][j] = max(dp[i][j-1],dp[i-1][j])

print(dp)

for i in range(len(second_name)+1):
    print(dp[i])