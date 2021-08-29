def LCS(s1, s2) :
    result = ""
    tempArr = []
    s1len = len(s1)
    s2len = len(s2)
    dp = [[0]*(s2len+1) for _ in range(s1len+1)]
    
    for i in range(s1len+1):
        for j in range(s2len+1):
            if i==0 or j==0:
                dp[i][j] = 0
            elif s1[i-1] == s2[j-1]:
                dp[i][j] = dp[i-1][j-1]+1
                tempArr.append((-dp[i][j], i-1, j-1))
            else:
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])
    
    if dp[s1len][s2len] == 0:
      return (0, 0)    
    tempArr.sort(key = lambda x: x[0])
    resArr = []
    resArr.append(tempArr[0][2])
    w, x, y = tempArr[0][0]+1, tempArr[0][1], tempArr[0][2] 

    for temp in tempArr[1:]:
      if temp[0] != w or temp[1] >= x or temp[2] >= y:
        continue
      resArr.append(temp[2])
      w += 1
      x = temp[1]
      y = temp[2]
    
    resArr.reverse()
  
    for res in resArr:
      result += s2[res]
    return (dp[s1len][s2len], result)

A = input()
B = input()

result = LCS(A, B)
if result[0] > 0:
  print(result[0])
  print(result[1])
else:
  print(result[0])