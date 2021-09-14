def solution(n, lost, reserve):
  answer = 0
  lost.sort()
  reserve.sort()
  fixed_lost = list(set(lost)-set(reserve))
  fixed_reserve = list(set(reserve)-set(lost))
  for i, lo in enumerate(fixed_lost):
    for j, res in enumerate(fixed_reserve):
      if lo == res+1 or lo == res-1:
        fixed_reserve[j] = -1
        fixed_lost[i] = 0
        break
    else:
      fixed_lost[i] = 1
  
  answer = n - sum(fixed_lost)
  return answer

print(solution(5, [2,4], [1,3,5]))
print(solution(5, [2,4], [3]))
print(solution(3, [3], [1]))

