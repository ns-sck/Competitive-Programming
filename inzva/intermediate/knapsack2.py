weights=[2,3,1]

profit= [4,6,8]

target = 4

dp =[ [0 for i in range(target+1)] for j in range(len(weights)+1)]


for i in range(1,len(weights)+1): 
    for w in range(1,target+1):
        if w - weights[i-1] >=0:
            dp[i][w] = max(dp[i-1][w-weights[i-1]]+ profit[i-1], dp[i-1][w])

        else:
            dp[i][w] = dp[i-1][w]

print(dp)