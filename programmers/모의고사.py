def solution(answers):
  answer = []
  supoja = {}
  score = {1:0, 2:0, 3:0}
  supoja[1] = [1, 2, 3, 4, 5]
  supoja[2] = [2, 1, 2, 3, 2, 4, 2, 5]
  supoja[3] = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]
  
  for i in range(len(answers)):
    if answers[i] == supoja[1][i%len(supoja[1])]:
      score[1] += 1
    if answers[i] == supoja[2][i%len(supoja[2])]:
      score[2] += 1
    if answers[i] == supoja[3][i%len(supoja[3])]:
      score[3] += 1
  
  result = sorted(score.items(), key=lambda x: (-x[1],x[0]))
  answer.append(result[0][0])
  if result[0][1] == result[1][1]:
    answer.append(result[1][0])
  if result[0][1] == result[2][1]:
    answer.append(result[2][0])
  return answer

print(solution([1,2,3,4,5]))
print(solution([1,3,2,4,2]))