def check_nick(nick1, nick2, k):
  diff = 0
  idx1, idx2 = 0, 0
  while idx1 < len(nick1) and idx2 < len(nick2):
    if nick1[idx1] == nick2[idx2]:
      idx1 += 1
      idx2 += 1
    else:
      diff += 1

      for i in range(idx2, len(nick2)):
        if nick1[idx1] == nick2[i]:
          idx2 = i
          break
      else:
        idx1 += 1
  
  diff += len(nick1) - idx1
  diff += len(nick2) - idx2
  if diff <= k:
    return False
  
  return True

def check_email(email1, email2):
  email1_left, email1_right = email1.split('@')
  email2_left, email2_right = email2.split('@')
  
  if email1_left == email2_left:
    return False
  
  if not check_nick(email1_left, email2_left, 1):
    if email1_right == email2_right:
      return False
    else:
      return True
  
  return True

def check_unique():
  # 닉네임과 이메일을 한꺼번에 검사해서 중복체크를 해줘야 했는데, 따로 검사해서 틀린 것 같습니다.
  pass

def solution(nicks, emails):
  
  valid_id = [True for _ in range(len(nicks))]
  for i in range(len(nicks)-1):
    for j in range(i+1, len(nicks)):
      valid_id[j] = valid_id[j] & check_nick(nicks[i], nicks[j], 2)
      
  valid_email = [True for _ in range(len(emails))]
  for i in range(len(emails)-1):
    for j in range(i+1, len(emails)):
      valid_email[j] = valid_email[j] & check_email(emails[i], emails[j])
  
  answer = 0
  for i in range(len(valid_id)):
    if valid_id[i] and valid_email[i]:
      answer += 1
  return answer


print(solution(["imhero111", "moneyman", "hero111", "imher1111", "hro111", "mmoneyman", "moneymannnn"], ["superman5@abcd.com", "batman432@korea.co.kr", "superman@abcd.com", "supertman5@abcd.com", "superman@erty.net", "batman42@korea.co.kr", "batman432@usa.com"]))