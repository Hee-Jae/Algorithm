import sys
input = sys.stdin.readline

def gcd(a, b):
  while b != 0:
    a, b = b, a%b
    
  return a

T = int(input())

for _ in range(T):
  a, b = map(int, input().split())
  print(a*b//gcd(a,b))