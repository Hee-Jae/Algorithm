from collections import Counter

def check_issue(data, n, k):
  for d in data:
    if d < k:
      return False
    
  if sum(data) < 2*n*k:
    return False
  return True
  
def solution(research, n, k):
  info = {}
  for idx, re in enumerate(research):
    count = Counter(re)
    for key, value in count.items():
      if key not in info:
        info[key] = [0]*len(research)
      info[key][idx] = value
  
  result = {}
  for key, value in info.items():
    result[key] = 0
    for i in range(len(value)-n+1):
      if check_issue(value[i:i+n], n, k):
        result[key] += 1
  
  max_value = 1
  max_key = 'zz'
  for key, value in result.items():
    if value >= max_value and key < max_key:
      max_value = value
      max_key = key
  
  if max_key == 'zz':
    return 'None'
  else:
    return max_key

print(solution(["abaaaa","aaa","abaaaaaa","fzfffffffa"], 2, 2))
print(solution(["yxxy","xxyyy"], 2, 1))
print(solution(["yxxy","xxyyy","yz"], 2, 1))
print(solution(["xy","xy"], 1, 1))