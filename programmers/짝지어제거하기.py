def solution(s):
  stack = []
  for ss in s:
    if stack:
      if stack[-1] == ss:
        stack.pop()
      else:
        stack.append(ss)
    else:
      stack.append(ss)
      
  if stack:
    return 0
  else:
    return 1

print(solution('baabaa'))
print(solution('cdcd'))