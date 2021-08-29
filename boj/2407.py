dp = [[1]]

for i in range(1,101):
  dp.append([]);
  for j in range(i+1):
    if(j == 0 or j == i):
      dp[i].append(1)
    else:
      dp[i].append(dp[i-1][j-1] + dp[i-1][j])

# print(dp)
a,b = input().split()
a = int(a)
b = int(b)
print(dp[a][b])