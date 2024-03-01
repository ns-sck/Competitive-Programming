import sys


MAX_INT=sys.maxsize
n=4

dp=[MAX_INT]*(1<<n)

dp[0]=0

cost = [[0,3,2,2],[3,4,2,3],[2,2,1,1],[2,3,1,0]]   



for mask in range(1<<n):
    x = bin(mask).count('1')
    for i in range(n):

        if mask&(1<<i)==0:
            new_mask=mask|(1<<i)
            dp[new_mask]=min(dp[new_mask],dp[mask]+cost[x][i])

print(dp[(1<<n)-1])