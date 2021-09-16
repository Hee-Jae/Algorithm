import math

def solution(left, right):
  answer = 0
  for i in range(left, right+1):
    if math.sqrt(i)%1 == 0:
      answer -= i
    else:
      answer += i
  return answer

print(solution(13, 17))
print(solution(24, 27))