import sys
input = sys.stdin.readline

C = int(input())

def gcd(a, b):
  if a == 1 or b == 1:
    return 1
  while b:
    a, b = b, a%b
  return a

gcd_arr = [[0]*1001 for _ in range(1001)]
for i in range(1, 1001):
  for j in range(i+1, 1001):
    gcd_arr[i][j] = gcd(i,j)
      

for _ in range(C):
  N = int(input())
  ans = 0
  for i in range(1, N+1):
    for j in range(i+1, N+1):
      if(gcd_arr[i][j] == 1):
        ans += 1
  ans = ans*2 + 3
  print(ans)