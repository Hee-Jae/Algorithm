def make124(n, ans):
  if n == 0:
    return ans
  
  number = n%3
  if number == 0:
    number = 4
    n -= 1
  
  return make124(n//3, ans+str(number))

def solution(n):
  return ''.join(reversed(make124(n, '')))
    

for i in range(1,23):
  print(i, ":", solution(i))