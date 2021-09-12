def isprime(n):
  if n < 2:
    return False
  if n == 2: 
    return True    
  if not n & 1: 
    return False
  for x in range(3, int(n**0.5)+1, 2):
    if n % x == 0:
      return False
  return True

def ntok(n, k):
  res = ''
  while n:
    res += str(n%k)
    n = n//k
  return ''.join(reversed(res))

def solution(n, k):
  answer = 0
  global isPrime
  
  kjin = ntok(n, k)
  klist = kjin.split('0')
  for i in klist:
    if i.isdigit() and isprime(int(i)):
      answer += 1
  return answer

print(solution(437674, 3))
print(solution(110011, 10))
print(solution(127, 2))
# for i in range(1, 1000):
#   try:
#     solution(i, 2)
#   except:
#     print(i)