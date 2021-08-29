import sys
input = sys.stdin.readline

N = int(input())
room = []
for _ in range(N):
  start,end,people = map(int, input().split())
  room.append(people)

dp = []
for _ in range(N): dp.append(0)

if(N==1): print(room[0])
elif(N==2): print(max(room[0],room[1]))
elif(N==3): print(max(room[0]+room[2], room[1]))
else:
  for i in range(3,N):
    dp[0],dp[1],dp[2] = room[0],room[1], room[2]+room[0]
    dp[i] = room[i]+max(dp[i-2],dp[i-3])
  # for i in range(N):
  #   print(dp[i], end=" ")
  print(max(dp[N-1],dp[N-2]))
