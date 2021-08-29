import sys
input = sys.stdin.readline

N = int(input())
tree = [[] for _ in range(N+1)]
W = [[] for _ in range(N+1)]
visit = [0 for _ in range(N+1)]

for _ in range(N):
  M = list(map(int, input().split()))
  mlen = len(M)
  node = M[0]
  for i in range(2,mlen, 2):
    adjNode = M[i-1]
    cost = M[i]
    W[node].append((adjNode, cost))

maxdist = 0
maxnode = 1
def dfs(node, visit, cost):
  global maxdist, maxnode
  if maxdist < cost :
    maxdist = cost
    maxnode = node
  for next,co in W[node]:
    if(visit[next] == 0):
      visit[next] = 1
      dfs(next, visit, cost+co)

visit[1] = 1
dfs(1,visit,0)

visit = [0 for _ in range(N+1)]
visit[maxnode] = 1
dfs(maxnode, visit, 0)

print(maxdist)