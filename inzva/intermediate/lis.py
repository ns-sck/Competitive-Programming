lst= [1,4,3,2,8,5,10,6]

dp = [1 for i in range(len(lst))]
for i in range(len(lst)):
    for j in range(i):
        if lst[i]>lst[j]:
            dp[i] = max(dp[j]+1,dp[i])

print(dp)