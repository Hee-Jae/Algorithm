def solution(gems):
  kind = {}
  gemlen = 0
  for gem in gems:
    kind[gem] = 0
    gemlen += 1

  count = len(kind)
  cnt = 1
  min_diff = 100000; min_s = 0; min_e = 0
  start = 0; end = 0
  kind[gems[end]] = 1
  while(1):
    if(cnt < count):
      end += 1
      gem = gems[end]
      if(kind[gem] == 0): cnt += 1
      kind[gem] += 1
    else:
      diff = end-start
      # print(diff,"=",end,"-",start)
      if(diff < min_diff):
        min_diff = diff
        min_s = start
        min_e = end
      gem = gems[start]
      if(kind[gem] > 1):
        start += 1
        kind[gem] -= 1
      else:
        end += 1
        if(end >= gemlen): break
        gem = gems[end]
        kind[gem] += 1
    
  answer = [min_s+1, min_e+1]
  return answer

gems = ["DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"]
# gems = ["1","1","2","2","3","3","1","2","3"]
# gems = ["AA", "AB", "AC", "AA", "AC"]
print(solution(gems))