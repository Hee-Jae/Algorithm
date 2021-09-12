def solution(student, k):
  answer = 0
  for i in range(len(student)):
    tmp = 0
    for j in range(i,len(student)):
      tmp += student[j]
      if tmp == k:
        answer += 1
              
  return answer
  
  
print(solution([0,1,0,0], 1))
print(solution([0, 1, 0, 0, 1, 1, 0], 2))
print(solution([0, 1, 0], 2))