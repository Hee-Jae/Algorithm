def LCS(s1, s2) :
    s1len = len(s1)
    s2len = len(s2)
    dp = [[0]*(s2len+1) for _ in range(s1len+1)]
    
    for i in range(s1len+1):
        for j in range(s2len+1):
            if i==0 or j==0:
                dp[i][j] = 0
            elif s1[i-1] == s2[j-1]:
                dp[i][j] = dp[i-1][j-1]+1
            else:
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])
    
    return dp[s1len][s2len]

A = input()
B = input()

result = LCS(A, B)
print(result)