import sys
from collections import deque
input = sys.stdin.readline

OFF, ON, MATCH, DIE= 0, 1, 2, 3
T = int(input())
for _ in range(T):
  n = int(input())
  arr = [0] + list(map(int, input().split()))
  state = [0] + [0 for _ in range(n)]
  
  q = deque()
  count = 0
  for i in range(1,n+1):
    if state[i] in (MATCH,DIE):
      continue
    cur = i
    
    while True:
      q.append(cur)
      state[cur] = ON
      next = arr[cur]
      
      if state[next] in (MATCH,DIE):
        while q:
          state[q.popleft()] = DIE
          count += 1
        break
      
      if state[next] == ON:
        flag = False
        while q:
          x = q.popleft()
          if x == next: flag = True
          if flag:
            state[x] = MATCH
          else:
            state[x] = DIE
            count += 1
        break
      
      cur = next
  print(count)