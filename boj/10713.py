def update(node, start, end, left, right):
  global tree
  if left <= start and end <= right:
    tree[node] += 1
    return   
  if right < start or end < left:
    return
  update(node*2, start, (start+end)//2, left, right)
  update(node*2+1, (start+end)//2+1, end, left, right)

def finalUpdate(node, start, end):
  global tree, visit
  if start == end:
    visit[start] = tree[node]
    return
  tree[node*2] += tree[node]
  tree[node*2+1] += tree[node]
  finalUpdate(node*2, start, (start+end)//2)
  finalUpdate(node*2+1, (start+end)//2+1, end)
  
N, M = map(int, input().split())
P = list(map(int, input().split()))
info = [0]
for _ in range(N-1):
  A, B, C = map(int, input().split())
  info.append((A,B,C))

tree = [0 for _ in range(262150)]
visit = [0 for _ in range(N)]
for i in range(len(P)-1):
  u, v = P[i], P[i+1]
  if(u > v):
    u, v = v, u
  update(1, 1, N-1, u, v-1)

finalUpdate(1, 1, N-1)
# print(visit)
# for i in range(1, 8):
  # print(i, " : ",tree[i])

total = 0
for i in range(1, len(visit)):
  x = info[i][0] * visit[i]
  y = info[i][1] * visit[i] + info[i][2]
  if x > y:
    total += y
  else:
    total += x

print(total)