def solution(id_list, report, k):
  answer = []
  id_dict = {}
  report_dict = {}
  for id_ in id_list:
    id_dict[id_] = set()
    report_dict[id_] = 0
  
  for rep in report:
    u, v = rep.split()
    id_dict[u].add(v)
  
  for value in id_dict.values():
    for id_ in value:
      report_dict[id_] += 1
  
  for key, value in id_dict.items():
    tmp = 0
    for v in value:
      if report_dict[v] >= k:
        tmp += 1
    answer.append(tmp)
  return answer

print(solution(["muzi", "frodo", "apeach", "neo"], ["muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi"], 2))