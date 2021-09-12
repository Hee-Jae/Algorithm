prime = []
isPrime = [False, False] + [True]*1000000
for i in range(2, 1001):
  for j in range(i+i, 1000001, i):
    isPrime[j] = False

for i in range(2,1000001):
  if isPrime[i]:
    prime.append(i)

def divide(array):
  if len(array) == 1:
    return array
  
  global prime
  pivot = 0
  for p in prime:
    if len(array) % p == 0:
      pivot = p
      break
  
  new_array = [[] for _ in range(pivot)]
  for idx, value in enumerate(array):
    new_array[idx%pivot].append(value)
  
  result = []
  for na in new_array:
    result += divide(na)
  return result
  
def solution(n):
  array = [i for i in range(1,n+1)]
  
  answer = divide(array)
  return answer

# print(solution(12))
# print(solution(1000000)[:10])