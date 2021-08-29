import sys
input = sys.stdin.readline

N = int(input())
JooGa = list(map(int, input().split()))


jh = N; sm = N
jh_cnt = 0; sm_cnt = 0

for m in JooGa:
  if(jh >= m):
    jh_cnt += jh//m
    jh %= m

asc = 0; dsc = 0
prev = JooGa[0]
for m in JooGa:
  if(m == prev):
    asc = 0; dsc = 0
    prev = m
    continue
  if(prev < m):
    dsc = 0
    asc += 1
    if(asc == 3):
      sm += sm_cnt*m
      sm_cnt = 0
      asc = 0
      continue
  if(prev > m):
    asc = 0
    dsc += 1
    if(dsc == 3):
      if(sm >= m):
        sm_cnt += sm//m
        sm %= m
        dsc = 0
        continue

jh_ans = jh + JooGa[-1]*jh_cnt
sm_ans = sm + JooGa[-1]*sm_cnt

if(jh_ans > sm_ans): print("BNP")
elif(jh_ans < sm_ans): print("TIMING")
else: print("SAMESAME")
