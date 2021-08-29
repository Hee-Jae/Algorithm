import math
def getGrad(x1, y1, x2, y2):
  return abs((y2-y1)/(x2-x1))

N = int(input())
arr = []
info = {}
for i in range(1, N+1):
  x, y = map(int, input().split())
  arr.append((x ,y, i))
  info[i] = (x,y)

maxGrad = 0
arr.sort()
result = []

for i in range(len(arr)-1):
  x1, y1, x2, y2 = arr[i][0], arr[i][1], arr[i+1][0], arr[i+1][1]
  temp = getGrad(x1, y1, x2, y2)
  result.append((temp, arr[i][2], arr[i+1][2]))
  if temp > maxGrad:
    maxGrad = temp

final = set()
for res in result:
  if res[0] == maxGrad:
    final.add(res[1])
    final.add(res[2])

A = min(final)
B = N
for key in final:
  if key == A:
    continue
  x1, y1, x2, y2 = info[A][0], info[A][1], info[key][0], info[key][1]
  if getGrad(x1, y1, x2, y2) == maxGrad:
    if key < B:
      B = key

print(A,B)