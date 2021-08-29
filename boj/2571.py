import sys
input = sys.stdin.readline

def getArea(x, y):
  global paper
  width = 0
  height = paper[x][y]
  result = 0
  while True:
    height = min(height,paper[x][y])
    width += 1
    y += 1
    result = max(result, height*width)
    if y >= 100:
      break
    if paper[x][y] == 0:
      break
    
  return result

paper = [[0]*100 for _ in range(100)]
N = int(input())
for _ in range(N):
  x, y = map(int, input().split())
  for i in range(10):
    paper[y+i][x:x+10] = [1 for _ in range(10)]

for i in range(1, 100):
  for j in range(100):
    if paper[i][j] == 0:
      continue
    paper[i][j] += paper[i-1][j]

maxArea = 0
for i in range(100):
  for j in range(100):
    if paper[i][j] == 0:
      continue
    tmp = getArea(i, j)
    if maxArea < tmp:
      maxArea = tmp

print(maxArea)
# for i in range(35):
#   for j in range(35):
#       print('{:2d}'.format(paper[i][j]), end=' ')
#   print()