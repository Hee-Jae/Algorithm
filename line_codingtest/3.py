def solution(jobs):
  answer = [jobs[0][2]]
  job_info = {}
  job_index = 0
  queue = [0]*101
  while job_index < len(jobs):
    
    cur_job = jobs[job_index]
    job_index += 1
    cur_second = cur_job[0]
    job_info[cur_job[2]] = [0, cur_job[1], cur_job[2], cur_job[3]]
    queue[cur_job[2]] = 1
    if answer[-1] != cur_job[2]:
      answer.append(cur_job[2])
      
    while sum(queue) > 0:
      cur_second += job_info[cur_job[2]][1]
      job_info[cur_job[2]] = [0, 0, cur_job[2], 0]
      queue[cur_job[2]] = 0
      
      while job_index < len(jobs) and jobs[job_index][0] <= cur_second:
        new_job = jobs[job_index]
        if new_job[2] not in job_info:
          job_info[new_job[2]] = [0, 0, new_job[2], 0]  
        job_info[new_job[2]][1] += new_job[1]
        job_info[new_job[2]][2] = new_job[2]
        job_info[new_job[2]][3] += new_job[3]
        queue[new_job[2]] = 1
        job_index += 1
      
      # print(job_info)
      if job_info[cur_job[2]][1] == 0:
        play_list = sorted(job_info.items(), key=lambda x: (x[1][3], -x[0]), reverse=True)
        # print(play_list)
        cur_job = play_list[0][1]
        if answer[-1] != cur_job[2] and sum(queue) > 0:
          answer.append(cur_job[2])
    
  return answer

print(solution([[1, 5, 2, 3], [2, 2, 3, 2], [3, 1, 3, 3], [5, 2, 1, 5], [7, 1, 1, 1], [9, 1, 1, 1], [10, 2, 2, 9]]))
print(solution([[1, 2, 1, 5], [2, 1, 2, 100], [3, 2, 1, 5], [5, 2, 1, 5]]))
print(solution([[0, 2, 3, 1], [5, 3, 3, 1], [10, 2, 4, 1]]))
print(solution([[0, 5, 1, 1], [2, 4, 3, 3], [3, 4, 4, 5], [5, 2, 3, 2]]))