keypad = [[1,2,3],[4,5,6],[7,8,9],[10,11,12]]
dist = [[-1]*12 for _ in range(12)]
dir = [[0,1], [1,0], [0,-1], [-1,0]]
def getDist(x,y):
  queue = []
  queue.append((x,y))
  number = keypad[x][y]-1
  dist[number][number] = 0
  while(queue):
    u = queue[0][0]
    v = queue[0][1]
    prev = keypad[u][v]-1
    queue.pop(0)
    for i in range(4):
      xx = u + dir[i][0]
      yy = v + dir[i][1]
      if(xx < 0 or xx >= 4 or yy < 0 or yy >= 3): continue
      n = keypad[xx][yy]-1
      if(dist[number][n] != -1): continue
      dist[number][n] = dist[number][prev] + 1
      queue.append((xx,yy))

def solution(numbers, hand):
    answer = ''
    for i in range(4):
      for j in range(3):
        getDist(i,j)
    
    left=9; right=11
    for n in numbers:
      if(n==1 or n==4 or n==7):
        answer += 'L'
        left = n-1
      elif(n==3 or n==6 or n==9):
        answer += 'R'
        right = n-1
      else:
        if(n==0): n=11
        n -= 1
        if(dist[left][n] > dist[right][n]):
          answer += 'R'
          right = n
        elif(dist[left][n] < dist[right][n]):
          answer += 'L'
          left = n
        else:
          if(hand == 'left'):
            answer += 'L'
            left = n
          else:
            answer += 'R'
            right = n
    return answer


numbers = [7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2]	
hand = "left"
print(solution(numbers,hand))