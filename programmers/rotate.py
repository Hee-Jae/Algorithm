def rotate(arr):
    size = len(arr)
    new_arr = [[0]*size for _ in range(size)]

    for i in range(size):
        for j in range(size):
             new_arr[j][size-1-i] = arr[i][j]
    
    return new_arr

arr = [[1,2,3,4],[5,6,7,8],[9,10,11,12], [13,14,15,16]]
for _ in range(4):
  arr = rotate(arr)
  for i in arr:
    print(i)
  print("")