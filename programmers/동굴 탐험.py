from collections import deque
sys.setrecursionlimit(300000)
tree = {}
visit = []
def inorder(node):
  global visit
  global tree
  flag = False

  size = len(tree[node][0])
  
  for _ in range(size):
    child = tree[node][0].popleft()
    if(tree[child][1] == -1):
      tree[node][0].append(child)
      continue
    if(tree[child][1] != 0):
      on = tree[child][1]
      tree[on][1] = 0
      tree[child][1] = 0
      flag = True
    # if(visit[child]==0): print(child, end =" ")
    visit[child] = 1
    if not(tree[child][0]):
      continue
    tree[node][0].append(child)
    flag = flag | inorder(child)
  return flag

def solution(n, path, order):
    global visit
    global tree
    visit = [0 for _ in range(n)]
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
      tree[v][1] = -1
    # print(tree)
    visit = [0 for _ in range(n)]
    visit[0]=1
    while(inorder(0)): pass
    # print(visit)
    answer = True
    for i in visit:
      if(i==0):
        answer = False
        break
    return answer

n = 9
# path = [[0,1],[0,3],[0,7],[8,1],[3,6],[1,2],[4,7],[7,5]]
# order = [[8,5],[6,7],[4,1]]
# path = [[8,1],[0,1],[1,2],[0,7],[4,7],[0,3],[7,5],[3,6]]
# order = [[4,1],[5,2]]
path = [[0,1],[0,3],[0,7],[8,1],[3,6],[1,2],[4,7],[7,5]]
order = [[4,1],[8,7],[6,5]]
print(solution(n, path, order))