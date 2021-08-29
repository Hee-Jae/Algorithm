def solution(board):
  N = len(board)
  visit = [[-1]*N for _ in range(N)]
  dir = [[0,1],[1,0],[0,-1],[-1,0]]
  queue = [(0,0,0,0)]
  visit[0][0] = 0
  while(queue):
    x = queue[0][0]
    y = queue[0][1]
    prev_dir = queue[0][2]
    prev_cost = queue[0][3]
    queue.pop(0)
    for i in range(4):
      xx = x + dir[i][0]
      yy = y + dir[i][1]
      if(xx < 0 or xx >= N or yy < 0 or yy >= N): continue
      if(board[xx][yy] == 1): continue
      if(prev_dir == i+1 or prev_dir == 0): cost = prev_cost+1
      else: cost = prev_cost+6
      if(visit[xx][yy] != -1 and cost > visit[xx][yy]): continue
      if(xx == N-1 and yy == N-1):
        if(visit[xx][yy] > cost):
          visit[xx][yy] = cost
          continue
      visit[xx][yy] = cost
      queue.append((xx,yy,i+1,cost))
  
  answer = visit[N-1][N-1]*100
  return answer


# board = [[0,0,0],[0,0,0],[0,0,0]]
# board = [[0,0,0,0,0,0,0,1],[0,0,0,0,0,0,0,0],[0,0,0,0,0,1,0,0],[0,0,0,0,1,0,0,0],[0,0,0,1,0,0,0,1],[0,0,1,0,0,0,1,0],[0,1,0,0,0,1,0,0],[1,0,0,0,0,0,0,0]]
# board = [[0,0,1,0],[0,0,0,0],[0,1,0,1],[1,0,0,0]]
board = [[0,0,0,0,0,0],[0,1,1,1,1,0],[0,0,1,0,0,0],[1,0,0,1,0,1],[0,1,0,0,0,1],[0,0,0,0,0,0]]	
print(solution(board))