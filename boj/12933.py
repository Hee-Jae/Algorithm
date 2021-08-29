ori = {'q':0, 'u':0, 'a':0, 'c':0, 'k':0}

def valid_check(char):
  if char == 'u':
    if ori[char] > ori['q']: return False
  elif char == 'a':
    if ori[char] > ori['u']: return False
  elif char == 'c':
    if ori[char] > ori['a']: return False
  elif char == 'k':
    if ori[char] > ori['c']: return False
  return True

sound = input()
check = True
flag = True
ori_q_max = 0
for tic in sound:
  ori[tic] += 1

  if(tic == 'q'):
    if(ori_q_max < ori['q']):
      ori_q_max = ori['q']

  elif(tic == 'k'):
    for key in ori.keys():
      ori[key] -= 1
    
  check = valid_check(tic)
  if not check:
    flag = False
    break

for key in ori.keys():
  if ori[key] >= 1:
    flag = False

if(flag): print(ori_q_max)
else: print(-1)


