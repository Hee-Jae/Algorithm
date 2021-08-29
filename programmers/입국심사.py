def getTimes(x, times):
  res = 0
  for t in times:
    res += x//t
  return res

def solution(n, times):
    answer = 0
    low = 0; high = 1e18
    while(low+1 < high):
      mid = (low+high)//2
      tmp = getTimes(mid, times)
      if(tmp >= n): high = mid
      else: low = mid
      # print(low, high)
    answer = int(high)
    return answer


n = 6
times = [7, 10]
print(solution(n,times))