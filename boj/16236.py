from collections import deque

def bfs(baby):
    size, a,b = baby
    fish = []
    for i in range(N):
        for j in range(N):
            if 0 < sea[i][j] < size:
                fish.append((i,j))
    dist = []
    # print(fish)
    for fx,fy in fish:
        visited = [[0 for _ in range(N)] for _ in range(N)]
        n = 0
        q = deque()
        q.append((a,b))
        dx = [1,-1,0,0]
        dy = [0,0,1,-1]
        print("fish :",fx,fy)
        # print("a b :", a, b)
        while q:
            # print("q:",q)
            x,y = q.popleft()
            # print("x,y:",x,y)
            if visited[x][y] == 0:
                visited[x][y] = 1
            for k in range(4):
                nx = x + dx[k]
                ny = y + dy[k]
                if 0 <= nx < N and 0 <= ny < N:
                    # print("nx,ny:",nx,ny)
                    print("visited[0][2] : ", visited[0][2])
                    if visited[nx][ny] == 0:
                        # print("n,f",nx,ny,fx,fy)
                        if nx == fx and ny == fy:
                            n += 1
                            dist.append((n,nx,ny))
                            print("append:",n,nx,ny)
                            q.clear()
                            break
                        elif sea[nx][ny] > size:
                            visited[nx][ny] = 1
                        else:
                            if(visited[nx][ny] == 0):
                              visited[nx][ny] = 1
                              q.append((nx,ny))
                              n += 1
                    # print(visited)
            print("===")
        # print("n:",n)
    print(dist)
    return dist

N = int(input())
sea = [list(map(int, input().split())) for _ in range(N)]
size = 2

for i in range(N):
    for j in range(N):
        if sea[i][j] == 9:
            baby = (size,i,j) # μμ΄ μμΉ
time = 0
mama = 1
while mama:
    size1, x1, y1 = baby
    feeds = bfs(baby)
    print("feeds :",feeds)
    # feeds = sorted(feeds, key = lambda)
    if not feeds:
        mama = 0
        break
    break