import sys
input = sys.stdin.readline

memo = {}

def gop(a, b):
  N = len(a)
  result = [[0]*N for _ in range(N)]
  for i in range(N):
    for j in range(N):
      for k in range(N):
        result[i][j] = (result[i][j] + (a[i][k] * b[k][j])%1000)%1000
  return result

def solution(M, K):
  global memo
  if K == 1:
    return M
  if K in memo:
    return memo[K]
  
  if K%2 == 0:
    memo[K] = gop(solution(M, K//2), solution(M, K//2))
    return memo[K]
  else:
    memo[K] = gop(solution(M, K-1), M)
    return memo[K]

N, B = map(int, input().split())
matrix = [[] for _ in range(N)]

for i in range(N):
  matrix[i] = list(map(int, input().split()))

answer = solution(matrix, B)
answer = list(map(lambda x: list(map(lambda y: y%1000, x)), answer))

for ans in answer:
  print(*ans)