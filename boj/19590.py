import sys
input = sys.stdin.readline

N = int(input())
bid = []
for _ in range(N):
  a = int(input())
  bid.append(a)

bid.sort(reverse=True)
# for i in range(N): print(bid[i], end=" ")
halfsum=0
for i in range(1,N):
  halfsum += bid[i]

# print("halfsum :", halfsum)
if(bid[0]>=halfsum): print(bid[0]-halfsum)
else:
  if((bid[0]+halfsum)%2): print(1)
  else: print(0)