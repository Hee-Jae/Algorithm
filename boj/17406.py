import sys
import itertools as it
input = sys.stdin.readline

N,M,K = map(int, input().split())
array = [list(map(int, input().split())) for _ in range(N)]

oper = []
for _ in range(K):
  op = list(map(int, input().split()))
  oper.append(op)

def getMin(arr):
  res = 1e9
  for i in arr:
    s = sum(i)
    if(s < res): res = s
  return res

def rotate(arr, dir):
  size = dir[2]*2
  step = dir[2]
  for s in range(size, 0, -2):
    x = dir[0]-step-1
    y = dir[1]+step-1
    temp = arr[x][y]
    for m in range(s): arr[x][y-m] = arr[x][y-m-1]
    
    x = dir[0]-step-1
    y = dir[1]-step-1
    for m in range(s): arr[x+m][y] = arr[x+m+1][y]

    x = dir[0]+step-1
    y = dir[1]-step-1
    for m in range(s): arr[x][y+m] = arr[x][y+m+1]

    x = dir[0]+step-1
    y = dir[1]+step-1
    for m in range(s-1) : arr[x-m][y] = arr[x-m-1][y]
    
    arr[dir[0]-step][dir[1]+step-1] = temp
    step -= 1
  return arr

seq = [i for i in range(K)]
permu = it.permutations(seq, K)
ans = 1e9
for e in permu:
  new_arr = [item[:] for item in array]
  res = rotate(new_arr, oper[e[0]])
  for k in e[1:]:
    res = rotate(res, oper[k])
  
  tmpMin = getMin(res)
  if(ans > tmpMin) : ans = tmpMin


print(ans)
      