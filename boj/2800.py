import sys
from itertools import combinations
input = sys.stdin.readline

N = input()
size = len(N)
numlist = []; oplist = []
stack = []
paren =[]
num = -1
for i in range(size):
  if(i==size-1):
    if(num >= 0): numlist.append(num)
  elif(N[i]=='('):
    if(num >= 0):
      numlist.append(num)
      num = -1
    stack.append(len(numlist))
  elif(N[i] == ')'):
    if(num >= 0):
      numlist.append(num)
      num = -1
    pair = stack.pop()
    paren.append((pair, len(numlist)-1))
  elif(N[i].isdigit()):
    if(num == -1): num = int(N[i])
    else: num = num * 10 + int(N[i])
  else:
    oplist.append(N[i])
    if(num >= 0):
      numlist.append(num)
      num = -1

psize = len(paren)
# if(psize==1): psize+=1
for i in range(len(numlist)):
  numlist[i] = str(numlist[i])

ans = []
for i in range(psize):
  combi = combinations(paren, i)
  for com in combi:
    copy_num = numlist[:]
    for p in com:
      copy_num[p[0]] = "(" + copy_num[p[0]]
      copy_num[p[1]] += ")"
    temp = ''
    for j in range(len(copy_num)):
      if (j < len(copy_num)-1):
        temp += (copy_num[j] + oplist[j])
      else: temp += copy_num[j]
    ans.append(temp)

ans = list(dict.fromkeys(ans))
ans.sort()
for a in ans:
  print(a)
# print(numlist)
# print(oplist)
# print(paren)