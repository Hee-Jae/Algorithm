from itertools import combinations
import math

def OddCnt(num):
  cnt = 0
  for n in num:
    if int(n)%2 == 1:
      cnt += 1
  return cnt

def getCnt(num, cnt):
  global maxCnt, minCnt
  if len(num) == 1:
    cnt += OddCnt(num)
    if cnt > maxCnt:
      maxCnt = cnt
    if cnt < minCnt:
      minCnt = cnt
    return

  elif len(num) == 2:
    n = int(num[0]) + int(num[1])
    getCnt(str(n), cnt+OddCnt(num))
    
  else:
    arr = [i for i in range(1, len(num))]
    odd = OddCnt(num)
    comb = combinations(arr, 2)
    for com in comb:
      a = int(num[0:com[0]])
      b = int(num[com[0]:com[1]])
      c = int(num[com[1]:])
      n = a+b+c
      getCnt(str(n), cnt+odd)

maxCnt = 0
minCnt = math.inf

N = input()
getCnt(N, 0)
print(minCnt, maxCnt)