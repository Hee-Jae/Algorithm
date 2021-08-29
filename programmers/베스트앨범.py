def solution(genres, plays):
  totalscore = {}
  musiclist = {}
  index = 0
  for genre in genres:
      if genre in musiclist:
        musiclist[genre].append((-plays[index], index))
        totalscore[genre] += plays[index]
      else:
        musiclist[genre]=[(-plays[index], index)]
        totalscore[genre] = plays[index]
      index += 1
  
  for key in musiclist.keys():
    musiclist[key].sort()

  totalscore = sorted(totalscore.items(), key=(lambda x:x[1]), reverse=True)

  answer = []
  for key in totalscore:
    limit = 2
    for score in musiclist[key[0]]:
      answer.append(score[1])
      limit -= 1
      if(limit == 0): break
  
  return answer

genre = ["classic", "pop", "classic", "classic", "pop"]
plays = [500, 600, 150, 800, 2500]

solution(genre, plays)