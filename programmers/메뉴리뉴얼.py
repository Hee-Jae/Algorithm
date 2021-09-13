from itertools import combinations
from collections import defaultdict
def solution(orders, course):
  answer = []
  menu_com = defaultdict(int)
  answer_dict = defaultdict(list)
  answer_len = defaultdict(int)
  for n in course:
    for order in orders:
      order = sorted(order)
      combination = combinations(order, n)
      for comb in combination:
        menu_com[comb] += 1
  
  # for key, value in menu_com.items():
  #   print(key, value)
  for key, value in menu_com.items():
    key_len = len(key)
    if answer_len[key_len] < value and value >= 2:
      answer_len[key_len] = value
      answer_dict[key_len] = [key]
    elif answer_len[key_len] == value:
      answer_dict[key_len].append(key)
  
  for value in answer_dict.values():
    for v in value:
      answer.append(v)
  
  answer = list(map(lambda x: ''.join(x), answer))
  answer.sort()
  return answer

print(solution(["ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"], [2,3,4]))
print(solution(["ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD"], [2,3,5]))
print(solution(["XYZ", "XWY", "WXA"], [2,3,4]))