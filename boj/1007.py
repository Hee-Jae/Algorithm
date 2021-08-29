import sys, math
from itertools import combinations
input = sys.stdin.readline

def getLength(x1, x2, y1, y2):
  return math.sqrt((x2-x1)**2 + (y2-y1)**2)

T = int(input())
for _ in range(T):
  N = int(input())
  point = []
  sumX = 0; sumY = 0
  minLen = math.inf
  for _ in range(N):
    x, y = map(int, input().split())
    sumX += x
    sumY += y
    point.append((x,y))
  combi = list(combinations(point, N//2))
  combiLen = len(combi)//2
  for comb in combi[:combiLen]:
    x1 = 0; y1 = 0
    for xx, yy in comb:
      x1 += xx
      y1 += yy
    x2 = sumX - x1
    y2 = sumY - y1
    tmpLen = getLength(x1, x2, y1, y2)
    if tmpLen < minLen: minLen = tmpLen
  print(minLen)

