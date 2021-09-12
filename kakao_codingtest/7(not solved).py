from collections import deque

def solution(board, aloc, bloc):
  dir = [[0,1], [1,0], [-1,0], [0,-1]]
  board[aloc[0]][aloc[1]] = 2
  board[bloc[0]][bloc[1]] = 3
  row = len(board)
  column = len(board[0])
  
  q = deque()
  q.append(([b[:] for b in board], aloc, bloc, 2, 0))
  while(q):
    tmp_board, a, b, t, count = q.popleft()
    tmp_board = [tb[:] for tb in tmp_board]
    if t == 2:
      can_move = False
      for i in range(4):
        nx = a[0] + dir[i][0]
        ny = a[1] + dir[i][1]
        if nx < 0 or nx >= row or ny < 0 or ny >= column or tmp_board[nx][ny] == 0:
          continue
        can_move = True
        if tmp_board[nx][ny] == 3:
          return count+1
        tmp_board[a[0]][a[1]] = 0
        tmp_board[nx][ny] = 2
        q.append(([nb[:] for nb in tmp_board], a, b, 3, count+1))
        tmp_board[a[0]][a[1]] = 2
        tmp_board[nx][ny] = 1
      if not can_move:
        return count
      
    elif t == 3:
      can_move = False
      for i in range(4):
        nx = b[0] + dir[i][0]
        ny = b[1] + dir[i][1]
        if nx < 0 or nx >= row or ny < 0 or ny >= column or tmp_board[nx][ny] == 0:
          continue
        can_move = True
        if tmp_board[nx][ny] == 2:
          return count+1
        tmp_board[b[0]][b[1]] = 0
        tmp_board[nx][ny] = 3
        q.append(([nb[:] for nb in tmp_board], a, b, 2, count+1))
        tmp_board[b[0]][b[1]] = 3
        tmp_board[nx][ny] = 1
      if not can_move:
        return count
      
  return 0

print(solution([[1, 1, 1], [1, 1, 1], [1, 1, 1]], [1, 0], [1, 2]))