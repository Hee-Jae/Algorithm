def solution(lottos, win_nums):
  rank = {6:1, 5:2, 4:3, 3:4, 2:5, 1:6, 0:6}
  zero_cnt = 0
  equal_cnt = 0
  for lot in lottos:
    if lot == 0:
      zero_cnt += 1
    elif lot in win_nums:
      equal_cnt += 1
  
  answer = [rank[zero_cnt+equal_cnt], rank[equal_cnt]]
  return answer


print(solution([44, 1, 0, 0, 31, 25], [31, 10, 45, 1, 6, 19]))