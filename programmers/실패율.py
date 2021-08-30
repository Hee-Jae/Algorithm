from collections import Counter

def solution(N, stages):
    answer = [i for i in range(1, N+1)]
    fail_ratio = [[i,0] for i in range(0, N+1)]
    info = []
    stages.sort()
    
    users = len(stages)
    
    count = Counter(stages)
    for key, value in count.items():
      info.append((key, value))
    
    for data in info:
      if data[0] > N:
        break
      fail_ratio[data[0]][1] = data[1]/users
      users -= data[1]
    
    fail_ratio.sort(key= lambda x: (-x[1], x[0]))
    answer = [stage[0] for stage in fail_ratio if stage[0] != 0]
    return answer
  
  
print(solution(5, [2, 1, 2, 6, 2, 4, 3, 3]))
print(solution(4, [4,4,4,4,4]))