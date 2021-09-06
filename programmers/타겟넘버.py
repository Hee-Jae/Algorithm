from itertools import combinations

def solution(numbers, target):
  answer = 0
  n_sum = sum(numbers)
  for i in range(len(numbers)+1):
    combis = combinations(numbers, i)
    for comb in combis:
      if n_sum - (sum(comb)*2) == target:
        answer += 1
  return answer
  
print(solution([1,1,1,1,1],3))