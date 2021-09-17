def solution(n):
  answer = 0
  samjin = ''
  while n:
    samjin += str(n%3)
    n //= 3
  
  for sam in samjin:
    answer = answer*3 + int(sam)
  return answer

print(solution(45))
print(solution(125))