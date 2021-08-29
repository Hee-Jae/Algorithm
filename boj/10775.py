import sys
input = sys.stdin.readline

gate = []
def find(n):
  if(gate[n]==n): return n
  else:
    gate[n] = find(gate[n])
    return gate[n]

def union(a,b):
  gate[find(a)] = find(b)

G = int(input())
P = int(input())
for i in range(G+1):
  gate.append(i)

cnt = 0
planes = []
for _ in range(P):
  plane = int(input())
  planes.append(plane)
for p in planes:
  nextgate = find(p)
  if(nextgate==0): break
  cnt += 1
  union(nextgate, nextgate-1)
  # print("")
  # for i in range(G+1):
  #   print(gate[i], end=" ")
  # print("")

print(cnt)