import sys
input = sys.stdin.readline

N = int(input())
crain = list(map(int, input().split()))
M = int(input())
box = list(map(int, input().split()))
picked = [False] * M

crain.sort(key = lambda x : -x)
box.sort(key = lambda x : -x)

cnt = 0
for i in range(M):
  if picked[i]:
    continue
  
  cnt += 1
  idx = 0
  for j in range(i, M):
    if picked[j] == False and box[j] <= crain[idx]:
      picked[j] = True
      idx += 1
      if idx == N:
        break
  
  if not picked[i]:
    print(-1)
    exit()

print(cnt)