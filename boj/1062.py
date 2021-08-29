from itertools import combinations

def stoi(ch):
  return ord(ch)-ord('a')

def stob(char):
  excp = {'a':0, 'c':0, 'i':0, 'n':0, 't':0}
  bit = 0
  for ch in char:
    if ch in excp:
      continue
    bit |= (1<< (ord(ch)-ord('a')))
  
  return bit

arr = []
N, K = map(int, input().split())
for _ in range(N):
  s = input()
  s = s[4:-4]
  b = stob(s)
  arr.append(b)
  
if K < 5:
  print(0)
  
elif K == 5:
  print(arr.count(0))

else:
  excp = {stoi('a'):0, stoi('c'):0, stoi('i'):0, stoi('n'):0, stoi('t'):0}
  alpha = []
  value = 1
  for i in range(1,26):
    value <<= 1
    if i in excp:
      continue
    alpha.append(value)

  comb = combinations(alpha, K-5)
  cnt = 0
  maxCnt = 0
  for com in comb:
    cnt = 0
    tempSum = sum(com)
    for a in arr:
      if (tempSum | a) == tempSum:
        cnt += 1
    if(maxCnt < cnt):
        maxCnt = cnt
  
  print(maxCnt)