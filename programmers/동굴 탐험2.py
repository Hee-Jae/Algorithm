from collections import deque
import sys
sys.setrecursionlimit(300000)

tree = {}
visit = []
degree = []
def search(node):
  global visit
  global tree
  global degree
  visit[node] = 1
  # print(node, end=" ")
  if(tree[node][1] != 0):
    on = tree[node][1]
    degree[on] -= 1
    if(degree[on]==0): search(on)
  
  for child in tree[node][0]:
    if(visit[child]): continue
    degree[child] -= 1
    if(degree[child]==0): search(child)

def solution(n, path, order):
    global visit
    global tree
    global degree
    visit = [0 for _ in range(n)]
    degree = [1 for _ in range(n)]
    for i in range(n):
      tree[i] = [deque([]),0]
    
    for p in path:
      u,v = p[0], p[1]
      tree[u][0].append(v)
      tree[v][0].append(u)
    
    queue = deque([0])
    visit[0] = 1
    while(queue):
      cur = queue.popleft()
      size = len(tree[cur][0])
      for _ in range(size):
        next = tree[cur][0].popleft()
        if(visit[next]): continue
        tree[cur][0].append(next)
        queue.append(next)
        visit[next]=1
    
    for o in order:
      u, v = o[0], o[1]
      tree[u][1] = v
      degree[v] += 1
    # print(tree)
    if(degree[0] == 2): return False
    visit = [0 for _ in range(n)]
    search(0)
    # print(visit)
    answer = True
    for i in visit:
      if(i==0):
        answer = False
        break
    return answer

n = 9
path = [[0,1],[0,3],[0,7],[8,1],[3,6],[1,2],[4,7],[7,5]]
order = [[8,5],[6,7],[4,1]]
# path = [[8,1],[0,1],[1,2],[0,7],[4,7],[0,3],[7,5],[3,6]]
# order = [[4,1],[5,2]]
# path = [[0,1],[0,3],[0,7],[8,1],[3,6],[1,2],[4,7],[7,5]]
# order = [[4,1],[8,7],[6,5]]
n = 2
path = [[0,1]]
order = [[1,0]]
print(solution(n, path, order))