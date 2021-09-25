def solution(board, skill):
  answer = 0
  for s in skill:
    type_, r1, c1, r2, c2, degree = s
    if(type_ == 1):
      for i in range(r1,r2+1):
        for j in range(c1,c2+1):
          board[i][j] -= degree
    elif(type_ == 2):
      for i in range(r1,r2+1):
        for j in range(c1,c2+1):
          board[i][j] += degree
          
  for bd in board:
    for b in bd:
      if b > 0:
        answer += 1
  return answer

print(solution([[5,5,5,5,5],[5,5,5,5,5],[5,5,5,5,5],[5,5,5,5,5]], [[1,0,0,3,4,4],[1,2,0,2,3,2],[2,1,0,3,1,2],[1,0,1,3,3,1]]))