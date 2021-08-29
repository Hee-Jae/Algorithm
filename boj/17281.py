from itertools import permutations
from collections import deque
import sys

N = int(input())

inning = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]

play = permutations(range(1,9)) #타자 순서
ans = 0
cnt = 0
fsum = 0
for per in play:
    per = list(per)
    per.insert(3,0)
    cnt+=1
    idx = 0 # 타자 순서
    score = 0 # 전체 점수
    fsum = 0
    for i in range(N): #각 inning
        fsum=0
        out = 0
        field = deque()
        while out < 3:
          hit = inning[i][per[idx]]
          if hit != 0:
            fsum += hit
            field.append(hit)
            if fsum >= 4:
              while fsum >= 4:
                fsum -= field[0]
                field.popleft()
                score += 1
          else:
            out += 1
          idx = (idx+1)%9
        while field:
          field.popleft()

    ans = max(ans,score)
print(cnt)
print("ans : ",ans)