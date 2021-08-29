import sys, math
input = sys.stdin.readline

n, m ,r = map(int, input().split())
arr = [[math.inf if i !=j else 0 for j in range(n)] for i in range(n)]

item = list(map(int, input().split()))
for _ in range(r):
  a, b, l = map(int, input().split())
  a -= 1; b -= 1
  arr[a][b] = l
  arr[b][a] = l

for k in range(n):
  for i in range(n):
    for j in range(n):
      if arr[i][k] + arr[k][j] < arr[i][j]:
        arr[i][j] = arr[i][k] + arr[k][j]

maxCnt = 0
for i in range(n):
  tmpCnt = 0
  for j in range(n):
    if arr[i][j] <= m:
      tmpCnt += item[j]
    
  if maxCnt < tmpCnt:
    maxCnt = tmpCnt

print(maxCnt)