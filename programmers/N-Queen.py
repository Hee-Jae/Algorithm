count = 0
def check(pos,x,y):
  for i in range(x):
    if(pos[i]==y): return 0
    if(abs(x-i) == abs(pos[i]-y)): return 0
  return 1

def search(pos,x,y,n):
  global count
  if(x==n-1):
    # print(pos[0], pos[1], pos[2], y)
    count += 1
    return 1
  pos[x] = y
  for i in range(n):
    if(check(pos,x+1,i)):
      search(pos,x+1,i,n)

def solution(n):
  global count
  answer = 0
  pos = [0] * n
  for i in range(n): search(pos,0,i,n)
  answer = count
  return answer

print(solution(12))