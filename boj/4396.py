import sys
input = sys.stdin.readline

def getNum(x, y):
  global grd, now, dir, N
  cnt = 0
  if(now[x][y] == 'x'):
    for d in dir:
      xx = x + d[0]
      yy = y + d[1]
      if(xx < 0 or xx >= N or yy < 0 or yy >= N): continue
      if(grd[xx][yy] == '*'): cnt += 1
    return cnt
  return '.'

N = int(input())

grd = [input() for _ in range(N)]
now = [input() for _ in range(N)]

bomb = []
for i in range(N):
  for j in range(N):
    if(grd[i][j]=='*'): bomb.append((i,j))

fail = False
for i in range(N):
  for j in range(N):
    if(now[i][j] == 'x' and (i,j) in bomb): fail = True
    if(fail): break
  if(fail): break



dir = [[0,1],[1,0],[0,-1],[-1,0],[-1,-1],[-1,1],[1,-1],[1,1]]
ans = [[0]*N for _ in range(N)]
for i in range(N):
  for j in range(N):
    ans[i][j] = (getNum(i,j))

if not fail:
  for row in ans:
    for k in row:
      print(k, end="")
    print("")

if(fail):
  for b in bomb:
    x = b[0]
    y = b[1]
    ans[x][y] = '*'
  for row in ans:
    for k in row:
      print(k, end="")
    print("")