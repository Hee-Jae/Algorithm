from collections import deque

def solution(places):
  answer = []
  dir = [[0,1],[1,0],[0,-1],[-1,0]]
  q = deque()
  
  case = len(places)
  for i in range(case):
    flag = False
    for j in range(5):
      for k in range(5):
        if(places[i][j][k] == 'P'):
          visit = [[-1]*5 for _ in range(5)]
          while(q): q.popleft()
          q.append((j,k))
          visit[j][k] = 0
          while(q):
            front = q.popleft()
            x = front[0]
            y = front[1]
            for e in range(4):
              xx = x + dir[e][0]
              yy = y + dir[e][1]
              if(xx < 0 or xx >= 5 or yy < 0 or yy >= 5): continue
              if(visit[xx][yy] != -1): continue
              if(places[i][xx][yy] == 'X'): continue
              if(places[i][xx][yy] == 'O'):
                visit[xx][yy] = visit[x][y] + 1
                q.append((xx,yy))
              if(places[i][xx][yy] == 'P'):
                visit[xx][yy] = visit[x][y] + 1
                if(visit[xx][yy] <= 2):
                  flag = True
                  break
                q.append((xx,yy))
            if(flag): break # q loop
        if(flag): break # k loop
      if(flag): break # j loop
    if(flag): answer.append(0)
    else: answer.append(1)    
  return answer

places = [["POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"], ["POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"], ["PXOPX", "OXOXP", "OXPXX", "OXXXP", "POOXX"], ["OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"], ["PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"]]
print(solution(places))