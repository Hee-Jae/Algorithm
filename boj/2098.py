import sys
input = sys.stdin.readline
INF = 10000000
N = int(input())
start = 0
goal = (1 << N)-1
W = [list(map(int, input().split())) for _ in range(N)]
D = [[0]* (1 << N) for _ in range(N)]

def travel(cur, visited):
  if(visited == goal):
    if(W[cur][start]==0): return INF
    else: return W[cur][start]
  if(D[cur][visited] != 0): return D[cur][visited]
  cost = INF
  for i in range(N):
    if(W[cur][i]!=0 and not visited&(1<<i)):
      temp = travel(i, visited|(1<<i)) + W[cur][i]
      if(cost > temp): cost = temp
  D[cur][visited] = cost
  return cost

print(travel(start, 1<<start))

for i in range(1<<N):
  print("{0:>2}".format(i), end=" ")
print("\n")
for i in range(N):
  for j in range(1<<N):  
    print("{0:>2}".format(D[i][j]), end=" ")
  print("")