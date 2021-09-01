def solution(progresses, speeds):
  answer = []
  required = [0] * len(progresses)
  for i in range(len(progresses)):
    required[i] = (100-progresses[i]) // speeds[i]
    required[i] += 1 if (100-progresses[i]) % speeds[i] > 0 else 0
  
  cur = required[0]
  tmp = 1
  for req in required[1:]:
    if req > cur:
      answer.append(tmp)
      tmp = 1
      cur = req
    else: tmp += 1
    
  answer.append(tmp)
  
  return answer
  
print(solution([93, 30, 55], [1, 30, 5]))
print(solution([95, 90, 99, 99, 80, 99], [1, 1, 1, 1, 1, 1]	))