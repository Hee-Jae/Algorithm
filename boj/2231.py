def generate(n):
  res = n
  while n:
    t = n%10
    res += t
    n = n // 10
  return res

N = int(input())
for i in range(1,1000001):
  tmp = generate(i)
  if tmp == N:
    print(i)
    break

else:
  print(0)