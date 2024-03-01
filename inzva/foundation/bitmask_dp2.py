import sys


MAX_INT=sys.maxsize
n=3

dp=[MAX_INT]*(1<<n)

dp[0]=0

cost = [[4,3,1],[1,2,5],[0,4,1]]   



for mask in range(1<<n):
    x = bin(mask).count('1')
    print("current mask:", bin(mask))
    for i in range(n):
        if mask&(1<<i)==0:
            new_mask=mask|(1<<i)
            dp[new_mask]=min(dp[new_mask],dp[mask]+cost[x][i])
            print("new_mask:", bin(new_mask))
            for k,j in enumerate(dp):
                print(bin(k),j)
            
print(dp[(1<<n)-1])

print(dp)