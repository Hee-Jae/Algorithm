k = int(input())

tmpSum = 0
twos = 1
while True:
  twos *= 2
  tmpSum += twos
  if k <= tmpSum:
    break

low = tmpSum - twos + 1
high = tmpSum

ans = ""
while low < high:
  mid = (low+high)//2
  if low <= k <= mid:
    ans += "4"
    high = mid
  else:
    ans += "7"
    low = mid+1

print(ans)