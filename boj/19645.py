import sys
input = sys.stdin.readline

N = int(input())
a = list(map(int, input().split()))
sum = sum(a)

dp = [[False]*(sum+1) for _ in range(sum+1)]
dp[0][0] = True

for i in range(N):
  for j in range(sum,-1,-1):
    for k in range(sum,-1,-1):
      if(j - a[i] >= 0): dp[j][k] |= dp[j-a[i]][k]
      if(k - a[i] >= 0): dp[j][k] |= dp[j][k-a[i]]

ans = 0
for i in range(sum+1):
  for j in range(i+1):
    if(dp[i][j] and j >= (sum - i - j)):
      if(ans < (sum-i-j)): ans = (sum-i-j)

print(ans)