import sys, math
sys.setrecursionlimit(100000)
input = sys.stdin.readline

def update(idx, start, end, node):
  global dp, tree
  if start == end:
    tree[node] = dp[start]
  else:  
    if idx < start or end < idx:
      return -math.inf
    
    mid = (start+end)//2
    update(idx, start, mid, node*2)
    update(idx, mid+1, end, node*2+1)
    left = tree[node*2]
    right = tree[node*2+1]
    tree[node] = left if left > right else right
  return tree[node]

def find(left, right, start, end, node):
  global tree
  if right < start or end < left:
    return -math.inf
  if left <= start and end <= right:
    return tree[node]
  
  mid = (start+end)//2
  l = find(left, right, start, mid, node*2)
  r = find(left, right, mid+1, end, node*2+1)
  return l if l > r else r

N, D = map(int, input().split())
arrSize = 2**(math.ceil(math.log(N,2))+1)
arr = list(map(int, input().split()))
tree = [-math.inf for _ in range(arrSize)]
dp = [-math.inf for _ in range(N)]
dp[0] = arr[0]
update(0, 0, N-1, 1)

for i in range(1, N):
  tmp = find(max(0,i-D), i-1, 0, N-1,1)

  dp[i] = max(tmp + arr[i], arr[i])
  update(i, 0, N-1, 1)

print(max(dp))

