def solution(a):
    answer = -1
    if(len(a) <= 1): return 0
    info = [[] for _ in range(500001)]
    idx = 0
    for b in a:
      info[b].append(idx)
      idx += 1
    
    length = 0; alen = len(a)
    for i in range(len(info)):
      length = 0
      prev = -1
      for j in range(len(info[i])):
        if(info[i][j] == 0):
          if(info[i][j] >= alen-1): continue
          if(j < len(info[i])-1 and info[i][j]+1 == info[i][j+1]): continue
          prev = info[i][j]+1
          length += 2
        elif(info[i][j]-1 == info[i][j-1] or info[i][j]-1 == prev):
          if(info[i][j] >= alen-1): continue
          if(j < len(info[i])-1 and info[i][j]+1 == info[i][j+1]): continue
          prev = info[i][j]+1
          length += 2
        else:
          prev = info[i][j]-1
          length += 2
      if(answer < length):
        answer = length
    return answer

# a = [0]
# a = [5,2,3,3,5,3]
a = [0,3,3,0,7,2,0,2,2,0]
# a = [0, 0, 0, 2, 3, 4, 3, 5, 3, 1]
# a = [0, 0, 3, 1, 2, 1, 3, 4, 0, 1, 4]
# a = [0, 3, 1, 6, 0, 2, 0, 7, 1, 3, 4, 0, 5, 1, 1]
# a = [1, 2, 2, 1, 3]
# a = [1,1,1,1,2]
print(solution(a))