import sys
input = sys.stdin.readline

N = int(input())
arr = [0] + list(map(int, input().split()))
Sum = [0] + [0 for _ in range(N)]
for i in range (1, N+1):
  Sum[i] = Sum[i-1] + arr[i]

ans = 0
for i in range(2, N):
  ans = max(ans, Sum[N]-arr[1]-arr[i]+Sum[N]-Sum[i])
  
for i in range(2, N):
  ans = max(ans, Sum[N]-arr[N]-arr[i]+Sum[i-1])
  
for i in range(2, N):
  ans = max(ans, Sum[i]-arr[1]+Sum[N]-Sum[i-1]-arr[N])

print(ans)