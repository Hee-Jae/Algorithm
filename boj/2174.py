import sys
input = sys.stdin.readline


def chdir(d, op):
  if(op=='L'):
    if(d=='N'): return 'W'
    if(d=='W'): return 'S'
    if(d=='S'): return 'E'
    if(d=='E'): return 'N'

  elif(op=='R'):
    if(d=='N'): return 'E'
    if(d=='E'): return 'S'
    if(d=='S'): return 'W'
    if(d=='W'): return 'N'

move = {'N':[1,0], 'E':[0,1], 'S':[-1,0], 'W':[0,-1]}
A,B = map(int, input().split())
ddang = [[0]*A for _ in range(B)]

N,M = map(int, input().split())
dir = [0]*(N+1)
pos = [0]*(N+1)
for i in range(1,N+1):
  x,y,d = input().split()
  x = int(x); y = int(y)
  ddang[y-1][x-1] = i
  pos[i] = (x,y)
  dir[i] = d

crash = False
for i in range(M):
  bot, op, re = input().split()
  if(crash): continue
  bot = int(bot); re = int(re)
  if(op == 'L' or op == 'R'):
    for _ in range(re):
      dir[bot] = chdir(dir[bot], op)
  elif(op == 'F'):
    x = pos[bot][0]-1
    y = pos[bot][1]-1
    xx = x
    yy = y
    for _ in range(re):
      xx += move[dir[bot]][1]
      yy += move[dir[bot]][0]
      if(xx < 0 or yy < 0 or xx >= A or yy >= B):
        print("Robot", bot, "crashes into the wall")
        # print(xx+1,yy+1)
        crash = True
        break
      if(ddang[yy][xx] != 0):
        print("Robot", bot, "crashes into robot", ddang[yy][xx])
        # print(yy,xx)
        crash = True
        break
    if(crash): continue
    ddang[yy][xx] = ddang[y][x]
    ddang[y][x] = 0
    pos[bot] = (xx+1,yy+1)

if not crash: print("OK")