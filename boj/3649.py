import sys
input = sys.stdin.readline

while True:
  try:
    x = int(input()) * 10000000
    n = int(input())
    
    arr = [int(input()) for _ in range(n)]
    arr.sort()
    start, end = 0, n-1
    flag = True
    while start < end:
      if arr[start] + arr[end] == x:
        print('yes %d %d' %(arr[start], arr[end]))
        flag = False
        break
      
      elif arr[start] + arr[end] < x:
        start += 1
        
      else:
        end -= 1
  
    if flag:
      print("danger")
  except:
    break