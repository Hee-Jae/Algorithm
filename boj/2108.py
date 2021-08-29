import sys
from collections import Counter
input = sys.stdin.readline

N = int(input())
arr = [int(input()) for _ in range(N)]
arr.sort()
c = Counter(arr).most_common()
c.sort(key = lambda x : (-x[1], x[0]))
if len(c) > 1:
  if(c[0][1] == c[1][1]):
    ca = c[1][0]
  else:
    ca = c[0][0]
else:
  ca = arr[0]
print(round(sum(arr)/len(arr)))
print(arr[len(arr)//2])
print(ca)
print(max(arr)-min(arr))