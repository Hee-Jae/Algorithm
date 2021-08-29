import sys
input = sys.stdin.readline

def xgcd(a,b):
  d0 = a; d1 = b
  x0 = 1; x1 = 0

  while(d1 != 0):
    q = d0 // d1
    d0 = d0 - q*d1
    d0, d1 = d1, d0
    x0 = x0 - q*x1
    x0, x1 = x1, x0
  
  if(d0 != 1): return 0
  else:
    if(x0 <= 0): return x0+b
    else: return x0

t = int(input())
while(t):
  K,C = map(int, input().split())
  if(C==1): ans = K+1
  else: ans = xgcd(C,K)
  if(ans==0 or ans>1000000000): print("IMPOSSIBLE")
  else: print(ans)
  t-=1