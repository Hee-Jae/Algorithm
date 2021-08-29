import itertools as it

def solution(expression):
  numbers = []
  oper = []
  tmp = 0
  for x in expression:
    if(x=='+' or x=='-' or x=='*'):
      oper.append(x)
      numbers.append(tmp)
      tmp = 0
    else:
      tmp = tmp*10 + int(x)
  numbers.append(tmp)

  perms = it.permutations(['+','-','*'])
  answer = 0
  for perm in perms:
    nums = numbers[:]
    for p in perm:
      oplen = len(oper)
      for i in range(oplen):
        if(oper[i] == p):
          j = i+1
          while(nums[j] == -1): j+=1
          if(p == '+'): nums[j] = nums[i] + nums[j]
          elif(p == '-'): nums[j] = nums[i] - nums[j]
          elif(p == '*'): nums[j] = nums[i] * nums[j]
          nums[i] = -1
          print(nums)
    res = abs(nums[-1])
    if(answer < res): answer = res
  
  return answer

exp = "100-200*300-500+20"
print(solution(exp))