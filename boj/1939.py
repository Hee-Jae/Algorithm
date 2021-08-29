import sys
from collections import defaultdict, deque

input = sys.stdin.readline

path = defaultdict(lambda: defaultdict(int))
N, M = map(int, input().split())
for _ in range(M):
  A,B,C = map(int, input().split())
  path[A][B] = max(path[A][B], C)
  path[B][A] = max(path[B][A], C)


q = deque()
visit = [0] * (N+1)
U, V = map(int, input().split())

for next, cost in path[U].items():
  q.append(next)
  visit[next] = cost

# print(q)

# for k, v in path.items():
#   print("k :", k)
#   for kk, vv in path[k].items():
#     print(kk, vv)
while q:
  cur = q.popleft()
  for next, cost in path[cur].items():
    if next == U:
      continue
    nextCost = min(visit[cur], cost)
    if nextCost > visit[next]:
      q.append(next)
      visit[next] = nextCost

# print(visit)
print(visit[V])