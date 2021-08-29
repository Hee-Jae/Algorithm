import sys
input = sys.stdin.readline

sys.setrecursionlimit(10**9)

N = int(input())
sns = [[] for _ in range(N+1)]
visit = [0 for _ in range(N+1)]
# tree = [[] for _ in range(N+1)]
tree={}
adapt = 0

for _ in range(N-1):
  u, v = map(int, input().split())
  sns[v].append(u)
  sns[u].append(v)

def makeTree(node):
  for child in sns[node]:
    if(visit[child] == 0):
      if not node in tree:
        tree[node] = []
      tree[node].append(child)
      visit[child] = 1
      makeTree(child)

def dfs(node):
  global adapt
  if not node in tree:
    pass
  else:
    for child in tree[node]:
      dfs(child)
      if(visit[child] == -1):
        visit[node] = 2

visit[1] = 1
makeTree(1)
# print(tree)
for i in range(N+1):
  visit[i] = -1
dfs(1)
for i in visit:
  if i==2: adapt += 1
print(adapt)