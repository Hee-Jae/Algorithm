K = int(input())
s = input()

arr = [s[i:i+K] for i in range(0, len(s), K)]
res = [arr[r][::] if r%2==0 else arr[r][::-1] for r in range(len(arr))]

for i in range(K):
  for j in range(len(res)):
    try:
      print(res[j][i], end='')
    except:
      break