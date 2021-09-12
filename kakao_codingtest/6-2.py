def solution(board, skill):
  answer = 0
  row = len(board)
  col = len(board[0])
  new_board = [[0]*(col+1) for _ in range(row+1)]
  
  for s in skill:
    type_, r1, c1, r2, c2, degree = s
    if(type_ == 1):
      new_board[r1][c1] -= degree
      new_board[r2+1][c2+1] -= degree
      new_board[r1][c2+1] += degree
      new_board[r2+1][c1] += degree
      
    elif(type_ == 2):
      new_board[r1][c1] += degree
      new_board[r2+1][c2+1] += degree
      new_board[r1][c2+1] -= degree
      new_board[r2+1][c1] -= degree
  
  for i in range(1, row):
    for j in range(col):
      new_board[i][j] += new_board[i-1][j]
  
  for i in range(1, col):
    for j in range(row):
      new_board[j][i] += new_board[j][i-1]

  for i in range(row):
    for j in range(col):
      board[i][j] += new_board[i][j]
      
  for bd in board:
    for b in bd:
      if b > 0:
        answer += 1
  return answer

print(solution([[5,5,5,5,5],[5,5,5,5,5],[5,5,5,5,5],[5,5,5,5,5]], [[1,0,0,3,4,4],[1,2,0,2,3,2],[2,1,0,3,1,2],[1,0,1,3,3,1]]))