import sys
from collections import deque
input = sys.stdin.readline

dir = [(0,1), (1,0), (-1,0), (0,-1)]
N, M, K = map(int, input().split())
arr = [[0]*(M+1) for _ in range(N+1)]

for _ in range(K):
  x, y = map(int, input().split())
  arr[x][y] = 1

q = deque()
maxSize = 0
for i in range(1,N+1):
  for j in range(1,M+1):
    if arr[i][j] == 1:
      q.append((i,j))
      arr[i][j] = 0
      tmpSize = 1
      while q:
        x, y = q.popleft()
        for k in range(4):
          xx = x + dir[k][0]
          yy = y + dir[k][1]
          if 0 < xx <= N and 0 < yy <= M and arr[xx][yy] == 1:
            arr[xx][yy] = 0
            tmpSize += 1
            q.append((xx,yy))
      if maxSize < tmpSize:
        maxSize = tmpSize

print(maxSize)
        