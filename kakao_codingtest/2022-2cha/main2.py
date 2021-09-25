# 외부소스 출처 : https://github.com/kswamen/2021_kakao_2nd_bike_management_simulation

import requests
import json
import time
from collections import defaultdict, deque

BASE_URL = "https://huqeyhi95c.execute-api.ap-northeast-2.amazonaws.com/prod"
AUTHORIZATION = ''
N = 900
waiting_queue = []
user_grade = [100 for _ in range(N+1)]

def startAPI(problem):
  global AUTHORIZATION
  response = requests.post(BASE_URL + '/start',
                          headers={'X-Auth-Token': '6ca272f705cc80e8e5c8d1cfcefb98ad',
                                  'Content-Type': 'application/json'},
                          data=json.dumps({'problem': problem})).json()
  AUTHORIZATION = response['auth_key']

def WaitingLineAPI():
  global waiting_queue
  response = requests.get(BASE_URL + '/waiting_line',
                          headers={'Authorization': AUTHORIZATION,
                                  'Content-Type': 'application/json'}).json()
  
  waiting_queue = []
  # print(response['waiting_line'])
  for user in response['waiting_line']:
    waiting_queue.append(user['id'])
  # print(waiting_queue)

def GameResultAPI():
  response = requests.get(BASE_URL + '/game_result',
                          headers={'Authorization': AUTHORIZATION,
                                  'Content-Type': 'application/json'}).json()
  for result in response['game_result']:
    win_user = result['win']
    lose_user = result['lose']
    user_grade[win_user] += 5
    user_grade[lose_user] -= 3
    
    if user_grade[win_user] > 9999:
      user_grade[win_user] = 9999
      
    if user_grade[lose_user] < 0:
      user_grade[lose_user] = 0
  
def UserInfoAPI():
  response = requests.get(BASE_URL + '/user_info',
                          headers={'Authorization': AUTHORIZATION,
                                  'Content-Type': 'application/json'}).json()
  
def MatchAPI(data):
  response = requests.put(BASE_URL + '/match',
                          headers={'Authorization': AUTHORIZATION,
                                    'Content-Type': 'application/json'},
                          data=json.dumps(data)).json()
  print(json.dumps(response, indent=2))
  
    
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
  efficiency_score = response['efficiency_score']	
  accuracy_score1 = response['accuracy_score1']
  accuracy_score2 = response['accuracy_score2']
  score = response['score']
  print("efficiency_score", efficiency_score)
  print("accuracy_score1", accuracy_score1)
  print("accuracy_score2", accuracy_score2)
  print("score", score)

def make_match():
  result = []
  if len(waiting_queue) % 2 == 0:
    for i in range(0, len(waiting_queue), 2):
      result.append([waiting_queue[i], waiting_queue[i+1]])
      
  else:
    for i in range(0, len(waiting_queue)-1, 2):
      result.append([waiting_queue[i], waiting_queue[i+1]])
      
  return result

startAPI(2) # turn 1
for _ in range(596):
  
  WaitingLineAPI()
  
  match_data = {}
  matches = make_match()
  # print(matches)
  match_data['pairs'] = matches
  # print(match_data)
  MatchAPI(match_data)
  
  GameResultAPI()
  
  grade_data = {}
  grade_data['commands'] = []
  for user_id, grade in enumerate(user_grade[1:]):
    grade_data['commands'].append({"id": user_id, "grade":grade})
  
  ChangeGradeAPI(grade_data)
  
ScoreAPI()