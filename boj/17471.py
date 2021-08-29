import sys
import itertools
input = sys.stdin.readline

def search(u, v, entry):
  if(u==v): return 1
  queue = [u]
  visited = [0] * (N+1)
  visited[u] = 1
  while(queue):
    cur = queue[0]
    queue.pop(0)
    for next in range(1,N+1):
      if(edge[cur][next] == 0): continue
      if(visited[next]==0 and next in entry):
        if(next == v): return 1
        queue.append(next)
        visited[next] = 1
  return 0

def solve():
  mindiff = 10000000
  arealist = []
  for i in range(1,N+1): arealist.append(i)
  for i in range(1, (N//2)+1):
    nCr = list(itertools.permutations(arealist,i))
    for entry in nCr:
      red = []
      blue = []
      notAble = 0
      redcnt = 0
      bluecnt = 0
      for j in range(1,N+1):
        if j in entry: red.append(j)
        else: blue.append(j)
      for j in red:
        if(search(red[0],j,red)==0): notAble=1
      for j in blue:
        if(search(blue[0],j,blue)==0): notAble=1
      if(notAble==1): continue
      if(notAble==0):
        for j in red:
          redcnt += area[j]
        for j in blue:
          bluecnt += area[j]
      diff = abs(redcnt-bluecnt)
      if(mindiff > diff):
        mindiff = diff
  return mindiff

area = [0]

N = int(input())

state = [0]*(N+1)
edge = [[0] * (N+1) for _ in range(N+1)]
ar = map(int, input().split())
for i in ar:
  area.append(i)

for i in range(1,N+1):
  adjNode = list(map(int, input().split()))
  for j in adjNode[1:]:
    edge[i][j] = 1
    edge[j][i] = 1

ans = solve()
if(ans == 10000000): print("-1")
else: print(ans)