lst = [2,3,1]

target = 6

dp = [0 for i in range(target+1)]

dp[0]=1

for t in range(target+1):
    for coin in lst:
        if t-coin >= 0:
            dp[t] = dp[t]+dp[t-coin]

print(dp)