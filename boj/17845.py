import sys
input = sys.stdin.readline

N, K = map(int, input().split())
W, V = [0]*(K+1), [0]*(K+1)
for i in range(1,K+1):
  I, T = map(int, input().split())
  W[i], V[i] = T, I

dp = [[0]*(N+1) for _ in range(K+1)]
for i in range(1, K+1):
  for j in range(1, N+1):
    if W[i] > j:
      dp[i][j] = dp[i-1][j]
    else:
      dp[i][j] = max(dp[i-1][j], dp[i-1][j-W[i]] + V[i])

print(dp[i][j])