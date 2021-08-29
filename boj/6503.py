import sys
input = sys.stdin.readline

N = 1
while(True):
  N = int(input())
  if N == 0:
    break

  info = {}
  start = 0; end = 1
  sen = input()
  sen = sen[:-1]
  if N >= len(sen):
    print(len(sen))
    continue
  
  cnt = 1; total = 1
  info[sen[start]] = 1
  maxLen = 0

  while end < len(sen):
    if not sen[end] in info:
      info[sen[end]] = 0
    info[sen[end]] += 1
    if info[sen[end]] == 1:
      cnt += 1
    total += 1
    end += 1

    while cnt > N and start < end:
      info[sen[start]] -= 1
      total -= 1
      if info[sen[start]] == 0:
        cnt -= 1
      start += 1

    if maxLen < total:
        maxLen = total

  print(maxLen)