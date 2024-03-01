lst = [2,3,1]

target = 6

dp = [0 for i in range(target+1)]

dp[0]=1

for i in lst:
    for j in range(target,i-1,-1):
        dp[j] = dp[j] or dp[j-i]

print(dp)