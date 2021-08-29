import sys
input = sys.stdin.readline

N = int(input())
people = input().split()
people.sort()

gyebo = {}
for name in people:
  gyebo[name] = [0,[],[],[]]

M = int(input())
for _ in range(M):
  relation = input().split()
  ancestor = relation[1]
  son = relation[0]
  gyebo[ancestor][0] += 1
  gyebo[son][1].append(ancestor)
  gyebo[ancestor][2].append(son)

queue = []
for name in gyebo.keys():
  if(gyebo[name][0] == 0): queue.append(name)

while(queue):
  top = queue[0]
  ancestor = gyebo[top][1]
  son = gyebo[top][2]
  for s in son:
    if(gyebo[s][0] == 0):
      gyebo[top][3].append(s)
      gyebo[s][0] = -2
  if not ancestor: gyebo[top][0] = -1
  for act in ancestor:
    gyebo[act][0] -= 1
    if(gyebo[act][0] == 0): queue.append(act)
  queue.pop(0)

sijo = []
sijocnt = 0
for name in gyebo.keys():
  if(gyebo[name][0] == -1):
    sijocnt += 1
    sijo.append(name)

print(sijocnt)
for sj in sijo:
  print(sj, end=" ")
print("")
for name, son in gyebo.items():
  print(name, len(son[3]), end=" ")
  son[3].sort()
  for s in son[3]:
    print(s, end=" ")
  print("")