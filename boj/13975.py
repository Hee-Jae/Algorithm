import heapq
import sys
input = sys.stdin.readline

T = int(input())
for _ in range(T):
  pq = []
  K = int(input())
  arr = map(int, input().split())
  for n in arr:
    heapq.heappush(pq, n)
  
  total = 0
  while len(pq) > 1:
    x = heapq.heappop(pq)
    y = heapq.heappop(pq)
    xy = x+y
    total += xy
    heapq.heappush(pq, xy)

  print(total)