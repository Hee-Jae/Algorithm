import sys
input = sys.stdin.readline

INF = -9999999999
cycle = False

N,M = map(int, input().split())
adj = [[] for _ in range(N)]
info = [[0]*N for _ in range(N)]
dist = [INF]*N
prev_node = [0]*N
cycle_list = [0]*N

for _ in range(M):
  u, v, w = map(int, input().split())
  u, v = u-1, v-1
  adj[u].append((v,w))
  # info[u][v] = 1

def dfs(start, cur): 
  for node in adj[cur]:
    next = node[0]
    if(info[start][next] == 0):
      info[start][next] = 1
      dfs(start, next)

dist[0] = 0
for i in range(N):
  dfs(i,i)

for i in range(N):
  for j in range(N):
    for node in adj[j]:
      next = node[0]
      weight = node[1]
      if(dist[j] != INF and dist[next] < dist[j]+weight):
        dist[next] = dist[j]+weight
        prev_node[next] = j
        # info[j][next] = 1
        if(i==N-1):
          cycle_list[j] = 1
          cycle_list[next] = 1

# print(cycle_list)
# print("")
# for inf in info:
#   print(inf)
for i in range(N):
  node = cycle_list[i]
  if node == 0: continue
  if info[node][N-1] == 1:
    cycle = True

if(cycle or dist[N-1]==INF):
  print(-1)

else: 
  current = N-1
  path = [current+1]
  while(current != 0):
    current = prev_node[current]
    path.append(current+1)

  path.reverse()
  for p in path:
    print(p, end=" ")