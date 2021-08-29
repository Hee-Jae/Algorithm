import sys
input = sys.stdin.readline

def cal(x,y,op):
  if(op=='+'): return x+y
  elif(op=='*'): return x*y
  else: return x-y

N = int(input())
exp = input()
num = []
op = []
m_idx = 0
for i in range(N):
  if(i%2==0): num.append(int(exp[i]))
  else :
    op.append(exp[i])
    if(exp[i]=='-' and m_idx == 0): m_idx = i//2

size = len(num)
maxdp = [[0]*size for _ in range(size)]
mindp = [[0]*size for _ in range(size)]
dp = [[0]*size for _ in range(size)]
for i in range(size):
  maxdp[i][i] = num[i]
  mindp[i][i] = num[i]

x=0; y=0; p=0
for i in range(size):
  for j in range(size-i-1):
    maxdp[j][j+i+1] = cal(maxdp[j][j], maxdp[j+1][j+i+1], op[j])
    mindp[j][j+i+1] = cal(mindp[j][j], mindp[j+1][j+i+1], op[j])
    for p in range(j, j+i+1):
      temp = []
      temp.append(cal(maxdp[j][p], mindp[p+1][j+i+1], op[p]))
      temp.append(cal(mindp[j][p], maxdp[p+1][j+i+1], op[p]))
      temp.append(cal(mindp[j][p], mindp[p+1][j+i+1], op[p]))
      temp.append(cal(maxdp[j][p], maxdp[p+1][j+i+1], op[p]))
      temp.sort()
      maxdp[j][j+i+1] = max(maxdp[j][j+i+1], temp[3])
      mindp[j][j+i+1] = min(mindp[j][j+i+1], temp[0])
    
      # if(j > 0 and j >= m_idx): dp[j][j+i+1] = min(dp[j][j+i+1], x)
      # else: dp[j][j+i+1] = max(dp[j][j+i+1], x)
# print(temp)
# for ent in maxdp:
#   print(ent)

ans = maxdp[0][size-1]
print(ans)
