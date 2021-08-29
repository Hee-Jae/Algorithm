import sys
input = sys.stdin.readline

N,M = map(int, input().split())

W = [[0]*(N+1) for _ in range(N+1)]
visit = [0 for _ in range(N+1)]

queue = []

for _ in range(M):
  A, B = map(int, input().split())
  W[A][B] = 1
  W[B][A] = 1

def bfs(n,m):
  for i in range(1,N+1):
    visit[i] = 0
  
  queue.append(n)
  queue.append(m)
  visit[n]=1
  visit[m]=1
  while(queue):
    top = queue[0]
    queue.pop(0)
    for i,v in enumerate(W[top]):
      if(v == 0 or i==0): continue
      if(visit[i] == 0):
        visit[i] = visit[top]+1
        queue.append(i)
  
  cost = 0
  for i in range(1,N+1):
    cost += (visit[i]-1)*2
  
  return cost

mincost = 1<<31
chicken1 = 0
chicken2 = 0
for i in range(1,N):
  for j in range(i+1,N+1):
    cost = bfs(i,j)
    if(mincost > cost):
      # print(visit)
      mincost = cost
      chicken1 = i
      chicken2 = j

print(chicken1, chicken2, mincost)