import sys
input = sys.stdin.readline

def ntoz(n, z):
  length = len(n)
  ans = 0
  for i in n:
    if(i.isdigit()): i = int(i)
    else:
      alpha = ord(i)-ord('a')
      i = alpha+10
    ans = ans*z + i
  return ans

max = 1<<63
N,M = input().split()

Ax = 0
Bx = 0
for i in N:
  if(i.isdigit()): i = int(i)
  else: i  = (ord(i) - ord('a')) + 10
  if(i > Ax): Ax = i

for i in M:
  if(i.isdigit()): i = int(i)
  else: i  = (ord(i) - ord('a')) + 10
  if(i > Bx): Bx = i

Narr=[]
Marr=[]
for i in range(Ax+1, 37):
  Narr.append(ntoz(N,i))

for i in range(Bx+1, 37):
  Marr.append(ntoz(M,i))
# print(Narr)
# print(Marr)
cnt = 0
for idx, val in enumerate(Narr):
  for jdx, bal in enumerate(Marr):
    if(idx+Ax==jdx+Bx): continue
    if(val >= max or bal >= max): continue
    if(val==bal):
      cnt+=1
      X = val
      A = idx+Ax+1
      B = jdx+Bx+1
      
if(cnt == 0): print("Impossible")
elif(cnt >= 2): print("Multiple")
else: print(X,A,B)

