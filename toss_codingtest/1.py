def solution(name_list):
    answer = []
    profile = {}
    for name in name_list:
      if name in profile:
        profile[name] = chr(ord(profile[name])+1)
      else:
        profile[name] = 'A'
      answer.append(name + profile[name])
    return answer
  
name_list = ["김비바", "김비바", "이비바", "김토스", "이비바", "김비바"]
print(solution(name_list))