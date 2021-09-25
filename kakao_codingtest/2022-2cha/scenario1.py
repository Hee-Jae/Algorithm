# 외부소스 출처 : https://github.com/kswamen/2021_kakao_2nd_bike_management_simulation

import requests
import json
from collections import defaultdict

BASE_URL = "https://huqeyhi95c.execute-api.ap-northeast-2.amazonaws.com/prod"
AUTHORIZATION = ''
N = 30
TIME = 0
waiting_queue = []
waiting_info = [False for _ in range(N+1)] # 유저가 이미 대기열에 있는지
user_grade = [5000 for _ in range(N+1)]

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
    grade = user['grade']
    temp_user_info[user['id']] = grade
    
  for user in response['waiting_line']:
    if waiting_info[user['id']] == False:
      grade = temp_user_info[user['id']]
      waiting_queue.append((user['id'], grade))
      waiting_info[user['id']] = True
    
  waiting_queue.sort(key=lambda x: x[1])

def GameResultAPI():
  response = requests.get(BASE_URL + '/game_result',
                          headers={'Authorization': AUTHORIZATION,
                                  'Content-Type': 'application/json'}).json()

  for result in response['game_result']:
    win_user = result['win']
    lose_user = result['lose']
    taken = result['taken']
    
    user_grade[win_user] += (taken / 10)
    user_grade[lose_user] -= (taken / 10)
    user_grade[win_user] = min(user_grade[win_user], 9999)
    user_grade[lose_user] = max(user_grade[lose_user], 0)
  
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
  
def ScoreAPI():
  response = requests.get(BASE_URL + '/score',
                          headers={'Authorization': AUTHORIZATION,
                                  'Content-Type': 'application/json'}).json()
  
  print(response)

def make_match():
  global waiting_queue, waiting_info
  result = []
  
  if len(waiting_queue) % 2 == 0:
    for i in range(0, len(waiting_queue), 2):
      result.append([waiting_queue[i][0], waiting_queue[i+1][0]])
      waiting_info[waiting_queue[i][0]] = False
      waiting_info[waiting_queue[i+1][0]] = False
    waiting_queue = []
  
  else:
    for i in range(0, len(waiting_queue)-1, 2):
      result.append([waiting_queue[i][0], waiting_queue[i+1][0]])
      waiting_info[waiting_queue[i][0]] = False
      waiting_info[waiting_queue[i+1][0]] = False
    waiting_queue = [waiting_queue[-1]]
  
  return result

startAPI(1) # turn 1
for i in range(596):
  
  WaitingLineAPI()
  match_data = {}
  matches = []
  if i%2 == 0:
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