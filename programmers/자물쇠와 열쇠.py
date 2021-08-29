def check(key, lock, x, y, cnt):
    key_size = len(key)
    lock_size = len(lock)
    res = 1
    for i in range(key_size):
        for j in range(key_size):
            if(x+i < 0 or lock_size <= x+i or y+j < 0 or lock_size <= y+j): continue
            r = key[i][j] + lock[x+i][y+j]
            if(r==0 or r==2):
                res = 0
                break
            if(lock[x+i][y+j] == 0): cnt -= 1
    if(cnt > 0): res = 0
    return res

def rotate(arr):
    size = len(arr)
    new_arr = [[0]*size for _ in range(size)]

    for i in range(size):
        for j in range(size):
             new_arr[j][size-1-i] = arr[i][j]
    
    return new_arr

def solution(key, lock):
    M = len(key)
    N = len(lock)
    cnt = 0
    for row in lock:
        for c in row:
            if(c==0): cnt+=1
    answer = True
    if(cnt == 0): return answer
    res = 1
    for _ in range(4):
        key = rotate(key)
        for i in range(1-M, N):
            for j in range(1-M, N):
                res = check(key,lock,i,j,cnt)
                if(res == 1): break
            if(res == 1): break
        if(res == 1): break
    if(res == 0): answer = False
    return answer


key = [[1, 1, 1], [1, 1, 1], [1, 1, 1]]
lock = [[1, 1, 1], [1, 1, 1], [1, 1, 1]]

print(solution(key,lock))