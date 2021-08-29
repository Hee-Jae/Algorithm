import sys
input = sys.stdin.readline

def type1(x,y,d):
  global arr
  if(d==1):
    for i in range(y+1,M):
      if(arr[x][i]==6): break
      if(arr[x][i]==0): arr[x][i]='#'
  elif(d==2):
    for i in range(x+1,N):
      if(arr[i][y]==6): break
      if(arr[i][y]==0): arr[i][y]='#'
  elif(d==3):
    for i in range(y-1,-1,-1):
      if(arr[x][i]==6): break
      if(arr[x][i]==0): arr[x][i]='#'
  elif(d==4):
    for i in range(x-1,-1,-1):
      if(arr[i][y]==6): break
      if(arr[i][y]==0): arr[i][y]='#'

def type2(x,y,d):
  global arr
  if(d==1):
    for i in range(y+1,M):
      if(arr[x][i]==6): break
      if(arr[x][i]==0): arr[x][i]='#'
    for i in range(y-1,-1,-1):
      if(arr[x][i]==6): break
      if(arr[x][i]==0): arr[x][i]='#'  
  elif(d==2):
    for i in range(x+1,N):
      if(arr[i][y]==6): break
      if(arr[i][y]==0): arr[i][y]='#'
    for i in range(x-1,-1,-1):
      if(arr[i][y]==6): break
      if(arr[i][y]==0): arr[i][y]='#'
  elif(d==3):
    for i in range(y-1,-1,-1):
      if(arr[x][i]==6): break
      if(arr[x][i]==0): arr[x][i]='#'
    for i in range(y+1,M):
      if(arr[x][i]==6): break
      if(arr[x][i]==0): arr[x][i]='#'
  elif(d==4):
    for i in range(x+1,N):
      if(arr[i][y]==6): break
      if(arr[i][y]==0): arr[i][y]='#'
    for i in range(x-1,-1,-1):
      if(arr[i][y]==6): break
      if(arr[i][y]==0): arr[i][y]='#'

def type3(x,y,d):
  global arr
  if(d==1):
    for i in range(y+1,M):
      if(arr[x][i]==6): break
      if(arr[x][i]==0): arr[x][i]='#'
    for i in range(x-1,-1,-1):
      if(arr[i][y]==6): break
      if(arr[i][y]==0): arr[i][y]='#'
  elif(d==2):
    for i in range(x+1,N):
      if(arr[i][y]==6): break
      if(arr[i][y]==0): arr[i][y]='#'
    for i in range(y+1,M):
      if(arr[x][i]==6): break
      if(arr[x][i]==0): arr[x][i]='#'
  elif(d==3):
    for i in range(y-1,-1,-1):
      if(arr[x][i]==6): break
      if(arr[x][i]==0): arr[x][i]='#'
    for i in range(x+1,N):
      if(arr[i][y]==6): break
      if(arr[i][y]==0): arr[i][y]='#'
  elif(d==4):
    for i in range(y-1,-1,-1):
      if(arr[x][i]==6): break
      if(arr[x][i]==0): arr[x][i]='#'
    for i in range(x-1,-1,-1):
      if(arr[i][y]==6): break
      if(arr[i][y]==0): arr[i][y]='#'

def type4(x,y,d):
  global arr
  if(d==1):
    for i in range(y+1,M):
      if(arr[x][i]==6): break
      if(arr[x][i]==0): arr[x][i]='#'
    for i in range(x-1,-1,-1):
      if(arr[i][y]==6): break
      if(arr[i][y]==0): arr[i][y]='#'
    for i in range(x+1,N):
      if(arr[i][y]==6): break
      if(arr[i][y]==0): arr[i][y]='#'
  elif(d==2):
    for i in range(x+1,N):
      if(arr[i][y]==6): break
      if(arr[i][y]==0): arr[i][y]='#'
    for i in range(y+1,M):
      if(arr[x][i]==6): break
      if(arr[x][i]==0): arr[x][i]='#'
    for i in range(y-1,-1,-1):
      if(arr[x][i]==6): break
      if(arr[x][i]==0): arr[x][i]='#'
  elif(d==3):
    for i in range(y-1,-1,-1):
      if(arr[x][i]==6): break
      if(arr[x][i]==0): arr[x][i]='#'
    for i in range(x+1,N):
      if(arr[i][y]==6): break
      if(arr[i][y]==0): arr[i][y]='#'
    for i in range(x-1,-1,-1):
      if(arr[i][y]==6): break
      if(arr[i][y]==0): arr[i][y]='#'
  elif(d==4):
    for i in range(y-1,-1,-1):
      if(arr[x][i]==6): break
      if(arr[x][i]==0): arr[x][i]='#'
    for i in range(x-1,-1,-1):
      if(arr[i][y]==6): break
      if(arr[i][y]==0): arr[i][y]='#'
    for i in range(y+1,M):
      if(arr[x][i]==6): break
      if(arr[x][i]==0): arr[x][i]='#'

def clear():
  global arr,N,M
  for i in range(N):
    for j in range(M):
      if(arr[i][j]=='#'): arr[i][j]=0

def simulation(idx, clen):
  global cctv
  global simul
  global zerocnt
  global mincnt
  if(idx==clen):
    pass
  else:
    for i in range(1,5):
      simul[idx] = i
      zerocnt = 0
      for j in range(clen):
        if(arr[cctv[j][0]][cctv[j][1]] == 1):
          type1(cctv[j][0],cctv[j][1], simul[j])
        elif(arr[cctv[j][0]][cctv[j][1]] == 2):
          type2(cctv[j][0],cctv[j][1], simul[j])
        elif(arr[cctv[j][0]][cctv[j][1]] == 3):
          type3(cctv[j][0],cctv[j][1], simul[j])
        elif(arr[cctv[j][0]][cctv[j][1]] == 4):
          type4(cctv[j][0],cctv[j][1], simul[j])
      for j in range(N):
        for k in range(M):
          if(arr[j][k]==0): zerocnt+=1
      if(mincnt > zerocnt):
        mincnt = zerocnt
      # if(simul[0]==1 and simul[1]==1 and simul[2]==1 and simul[3]==1):
      #   if(simul[4]==3 and simul[5]==3):
      #     for mm in arr:
      #       print(mm)
        # print(simul)
        # for mm in arr:
        #   print(mm)
      clear()
      simulation(idx+1, clen)

N,M = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(N)]

cctv = []
simul = []
zerocnt = 0
mincnt = 100
for i in range(N):
  for j in range(M):
    if(arr[i][j]!=0 and arr[i][j]!=6 and arr[i][j]!=5 and arr[i][j]!=7):
      cctv.append([i,j])
    elif(arr[i][j]==5):
      for k in range(j+1,M):
        if(arr[i][k]==0): arr[i][k]=7
        if(arr[i][k]==6): break
      for k in range(i+1,N):
        if(arr[k][j]==0): arr[k][j]=7
        if(arr[k][j]==6): break
      for k in range(j-1,-1,-1):
        if(arr[i][k]==0): arr[i][k]=7
        if(arr[i][k]==6): break
      for k in range(i-1,-1,-1):
        if(arr[k][j]==0): arr[k][j]=7
        if(arr[k][j]==6): break

cctvlen = len(cctv)
for i in range(cctvlen): simul.append(1)

simulation(0,cctvlen)
for j in range(N):
  for k in range(M):
    if(arr[j][k]==0): zerocnt+=1
if(mincnt > zerocnt):
  mincnt = zerocnt
print(mincnt)
# print(" ")
# for i in range(N):
#   for j in range(M):
#     print(arr[i][j], end= " ")
#   print("")