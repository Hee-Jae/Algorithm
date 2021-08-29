root = {}

def find(a):
  if(root[a][0] == a):
    return a
  root[a][0] = find(root[a][0])
  return root[a][0]

def merge(a, b):
  b_friends = root[find(b)][1]
  target = find(a)
  root[find(b)][0] = target
  root[target][1] += b_friends

def get_frineds(a):
  return root[find(a)][1]
  
T = int(input())
for _ in range(T):
  F = int(input())
  root.clear()

  for _ in range(F):
    a, b = input().split()
    if not a in root:
      root[a] = [a,1]
    if not b in root:
      root[b] = [b,1]
    
    if(find(a) == find(b)):
      print(get_frineds(a))
    else:
      merge(a, b)
      print(get_frineds(a))
