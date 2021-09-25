# 외부소스 출처 : https://github.com/kswamen/2021_kakao_2nd_bike_management_simulation

import requests
import json
from collections import defaultdict

BASE_URL = "https://huqeyhi95c.execute-api.ap-northeast-2.amazonaws.com/prod"
AUTHORIZATION = ''
N = 30
TIME = 0
waiting_queue = defaultdict(list) # 유저 티어에 따른 대기열 {티어 : (id, from)}
waiting_info = defaultdict(int) # 유저가 이미 대기열에 있는지
user_grade = [100 for _ in range(N+1)]

def startAPI(problem):
  global AUTHORIZATION
  global TIME
  response = requests.post(BASE_URL + '/start',
                          headers={'X-Auth-Token': '6ca272f705cc80e8e5c8d1cfcefb98ad',
                                  'Content-Type': 'application/json'},
                          data=json.dumps({'problem': problem})).json()
  AUTHORIZATION = response['auth_key']
  TIME = response['time']

def WaitingLineAPI():
  global waiting_queue, waiting_info
  response = requests.get(BASE_URL + '/waiting_line',
                          headers={'Authorization': AUTHORIZATION,
                                  'Content-Type': 'application/json'}).json()
  
  user_info = UserInfoAPI()
  user_info = user_info['user_info']
  temp_user_info = {}
  for user in user_info:
    level = user['grade'] // 100 # 유저 티어는 grade / 100
    temp_user_info[user['id']] = level
    
  for user in response['waiting_line']:
    level = temp_user_info[user['id']]
    if waiting_info[user['id']] == 0:
      waiting_queue[level].append((user['id'], user['from']))
      waiting_info[user['id']] = 1
  
  for level in waiting_queue.keys():
    waiting_queue[level].sort(key=lambda x: x[1]) # 먼저 대기열에 들어온 유저 순서대로 정렬

def GameResultAPI():
  response = requests.get(BASE_URL + '/game_result',
                          headers={'Authorization': AUTHORIZATION,
                                  'Content-Type': 'application/json'}).json()

  for result in response['game_result']:
    win_user = result['win']
    lose_user = result['lose']
    user_grade[win_user] += 25 # 이기면 +25점
    user_grade[lose_user] -= 25 # 지면 -25점
    
    if user_grade[win_user] > 9999:
      user_grade[win_user] = 9999
      
    if user_grade[lose_user] < 0:
      user_grade[lose_user] = 0
  
def UserInfoAPI():
  response = requests.get(BASE_URL + '/user_info',
                          headers={'Authorization': AUTHORIZATION,
                                  'Content-Type': 'application/json'}).json()
  
  return response
  
def MatchAPI(data):
  global TIME
  response = requests.put(BASE_URL + '/match',
                          headers={'Authorization': AUTHORIZATION,
                                    'Content-Type': 'application/json'},
                          data=json.dumps(data)).json()
  print(json.dumps(response, indent=2))
  TIME = response['time']
  
    
def ChangeGradeAPI(data):
  response = requests.put(BASE_URL + '/change_grade',
                          headers={'Authorization': AUTHORIZATION,
                                    'Content-Type': 'application/json'},
                          data=json.dumps(data)).json()
  # print(json.dumps(response, indent=2))
  
  
def ScoreAPI():
  response = requests.get(BASE_URL + '/score',
                          headers={'Authorization': AUTHORIZATION,
                                  'Content-Type': 'application/json'}).json()
  
  print(response)

def make_match():
  global waiting_queue, waiting_info
  result = []
  want_match_anybody = [] # 매칭 취소 시간이 임박해서 그냥 아무나 매칭 됐으면 하는 사람
  del_info = defaultdict(int) # 매칭이 되어 대기 큐에서 제거될 유저
  move_level_info = defaultdict(list) # 다음 티어로 이동할 유저
  
  
  for key in waiting_queue.keys():
    value = waiting_queue[key]
    if len(value) == 0:
      continue
    if len(value) == 1:
      if(TIME-value[0][1] > 10 and TIME-value[0][1] < 14):
        move_level_info[key+1].append(value[0])
        del_info[key] += 1
      
      elif(TIME-value[0][1] >= 14):
        want_match_anybody.append(value[0][0])
        del_info[key] += 1
        
      continue
    
    if len(value) % 2 == 0:
      for i in range(0, len(value), 2):
        result.append([value[i][0], value[i+1][0]])
        del_info[key] += 2
        waiting_info[value[i][0]] = 0
        waiting_info[value[i+1][0]] = 0
    
    else:
      for i in range(0, len(value)-1, 2):
        result.append([value[i][0], value[i+1][0]])
        del_info[key] += 2
        waiting_info[value[i][0]] = 0
        waiting_info[value[i+1][0]] = 0

  for key, value in del_info.items():
    waiting_queue[key] += move_level_info[key]
    
  for key, value in del_info.items():
    del waiting_queue[key][:value]
  
  if len(want_match_anybody) % 2 == 0:
    for i in range(0, len(want_match_anybody), 2):
      result.append([want_match_anybody[i], want_match_anybody[i+1]])

  else:
    for i in range(0, len(want_match_anybody)-1, 2):
      result.append([want_match_anybody[i], want_match_anybody[i+1]])
      
  return result

startAPI(1) # turn 1
for _ in range(596):
  
  WaitingLineAPI()
  match_data = {}
  matches = make_match()
  match_data['pairs'] = matches
  
  MatchAPI(match_data)
  GameResultAPI()
  
  grade_data = {}
  grade_data['commands'] = []
  for user_id, grade in enumerate(user_grade[1:]):
    grade_data['commands'].append({"id": user_id, "grade":grade})
  
  ChangeGradeAPI(grade_data)
  
ScoreAPI()