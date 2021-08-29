import sys
input = sys.stdin.readline

def solution(nums):
    answer = 0
    
    ponketmon = [0] * 200001
    for num in nums:
      ponketmon[num] = 1
    
    psum = sum(ponketmon)
    if psum > len(nums)//2:
      answer = len(nums)//2
    else:
      answer = psum
    return answer
  
print(solution([3,1,2,3]))
print(solution([3,3,3,2,2,4]))
print(solution([3,3,3,2,2,2]))