import sys
input = sys.stdin.readline

N, H = map(int, input().split())
cave = [0 for _ in range(H+2)]

for t in range(N):
  n = int(input())
  if(t%2 == 0):
    cave[1] += 1
    cave[n+1] -= 1
  else:
    cave[H-n+1] += 1

for i in range(1,H):
  cave[i+1] += cave[i]

minSum = N
cnt = 0  
for i in range(1, H+1):
  if cave[i] < minSum:
    minSum = cave[i]
    cnt = 1
  elif cave[i] == minSum:
    cnt += 1

print(minSum, cnt)