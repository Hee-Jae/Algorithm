from collections import deque
def solution(n, edge):
    answer = 0
    visit = [0] * (n+1)
    way = {}
    for i in range(1,n+1):
      way[i] = []
    for ed in edge:
      u = ed[0]
      v = ed[1]
      way[u].append(v)
      way[v].append(u)
    
    q = deque([1])
    visit[1] = 1
    max_dist = 0
    while(q):
      cur = q.popleft()
      for next in way[cur]:
        if(visit[next] > 0): continue
        q.append(next)
        visit[next] = visit[cur] + 1
        if(visit[next] > max_dist): max_dist = visit[next]
    
    for dist in visit:
      if(dist==max_dist): answer+=1

    return answer

print(solution(6,[[3, 6], [4, 3], [3, 2], [1, 3], [1, 2], [2, 4], [5, 2]]))