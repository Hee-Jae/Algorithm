def gcd(a, b):
  while b != 0:
    a, b = b, a%b
  return a

def solution(w,h):
    times = gcd(w,h)
    base = (h//times) + (w//times) - 1
    answer = w*h - base*times
    return answer
  
print(solution(8,12))