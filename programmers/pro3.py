def solution(n, k, cmd):
  answer = ''
  stack = []
  table = [i for i in range(n)]
  for cm in cmd:
    # print("k :", k)
    # print(cm)
    
    if(cm[0] == 'C'):
      stack.append((k,table[k]))
      table.pop(k)
      if(k > len(table)-1): k -= 1
    elif(cm[0] == 'Z'):
      r = stack.pop()
      table.insert(r[0], r[1])
      if(r[0] <= k): k+=1
    elif(cm[0] == 'D'):
      k += int(cm[2])
    elif(cm[0] == 'U'):
      k -= int(cm[2])
  # print(table)
  tmp = "O"*n
  tmp = list(tmp)
  for x in stack:
    tmp[x[1]] = 'X'
  answer = answer.join(tmp)
  return answer

n = 8
k = 2
# cmd = ["D 2","C","U 3","C","D 4","C","U 2","Z","Z"]
cmd = ["D 2","C","U 3","C","D 4","C","U 2","Z","Z","U 1","C"]
print(solution(n,k,cmd))