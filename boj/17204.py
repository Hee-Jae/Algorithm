import sys
input = sys.stdin.readline

N, K = map(int, input().split())
arr = [int(input()) for _ in range(N)]
visit = [True] + [False for _ in range(N-1)]
cur = 0
cnt = 1
while True:
  next = arr[cur]
  if next == K:
    print(cnt)
    exit()
  if visit[next]:
    print(-1)
    exit()
  visit[next] = True
  cnt += 1
  cur = next
