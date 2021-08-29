arr=[1,1,1,1,1]
cnt=0
def btk(idx):
  
  global cnt
  cnt+=1
  if(idx==5):
    pass
  else:
    for i in range(1,5):
      arr[idx] = i
      print(arr)
      btk(idx+1)

btk(0)
# print(cnt)
      