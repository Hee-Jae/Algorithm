import sys
input = sys.stdin.readline

def iswin(board):
  for row in board:
    if(sum(row)%3==0 and not 0 in row):
      return True
  
  for c in range(3):
    s = 0
    for r in range(3):
      if(board[r][c] == 0):
        s = 1
        break
      s += board[r][c]
    if(s%3==0): return True
  
  s = board[0][0] + board[1][1] + board[2][2]
  if(board[0][0] == board[1][1] == board[2][2] and s > 0): return True
  s = board[0][2] + board[1][1] + board[2][0]
  if(board[0][2] == board[1][1] == board[2][0] and s > 0): return True

def dfs(board, hole, player, turn):
  if(turn==player): res = -1
  else: res = 1
  if not hole: return 0
  new_hole = hole[:]
  size = len(new_hole)
  tmp = 0
  for _ in range(size):
    put = new_hole.pop(0)
    x = put[0]; y = put[1]
    board[x][y] = turn
    if(iswin(board)):
      if(turn != player): res = -1
      if(turn == player): res = 1
    else:
      if(turn==1): tmp = dfs(board, new_hole, player, 2)
      elif(turn==2): tmp = dfs(board, new_hole, player, 1)
    board[x][y] = 0
    if(turn == player and res < tmp): res = tmp
    elif(turn != player and res > tmp): res = tmp
    new_hole.append(put)
  return res

board = [list(map(int, input().split())) for _ in range(3)]
hole = []
cnt1=0; cnt2=0
turn=0; player=0
for r in range(3):
  for c in range(3):
    if(board[r][c]==1): cnt1+=1
    elif(board[r][c]==2): cnt2+=1
    else: hole.append((r,c))
if(cnt1==cnt2):
  turn=1; player=1
else:
  turn=2; player=2

res = dfs(board, hole, player, turn)
if(res == 1): print("W")
elif(res == 0): print("D")
elif(res == -1): print("L")