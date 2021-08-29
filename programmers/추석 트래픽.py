def getTime(log):
  s = log[11:23]
  hour = int(s[0:2])
  minute = int(s[3:5])
  second = int(s[6:8])
  mili = int(s[9:])
  t = log[24:]
  t = float(t[:-1]) * 1000

  time = mili
  time += second*1000
  time += minute*60000
  time += hour*3600000
  time -= t
  start = time+1
  end = time+t
  return (start, end)

def solution(lines):
  times = []
  answer = 0; cnt = 0
  for line in lines:
    times.append(getTime(line))
  
  for time in times:
    for i in range(2):
      t = time[i]
      s = t+999
      cnt = 0
      for comt in times:
        if(comt[0] <= s and comt[1] >= t):
          cnt +=1
          # print(t, s, comt[0], comt[1])
      if(cnt > answer):
        answer = cnt
        # print(t, s)
  return answer

# lines = [
# "2016-09-15 20:59:57.421 0.351s",
# "2016-09-15 20:59:58.233 1.181s",
# "2016-09-15 20:59:58.299 0.8s",
# "2016-09-15 20:59:58.688 1.041s",
# "2016-09-15 20:59:59.591 1.412s",
# "2016-09-15 21:00:00.464 1.466s",
# "2016-09-15 21:00:00.741 1.581s",
# "2016-09-15 21:00:00.748 2.31s",
# "2016-09-15 21:00:00.966 0.381s",
# "2016-09-15 21:00:02.066 2.62s"
# ]

# lines =  [
# "2016-09-15 01:00:04.002 2.0s",
# "2016-09-15 01:00:07.000 2s"
# ]

lines = ["2016-09-15 01:00:04.001 2.0s", "2016-09-15 01:00:07.000 2s"]
print(solution(lines))