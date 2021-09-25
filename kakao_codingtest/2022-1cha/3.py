import math

def solution(fees, records):
  answer = []
  fee_info = []
  car_dict = {}
  fee_dict = {}
  time_dict = {}
  for rec in records:
    time, car, inout = rec.split()
    hour, minute = time.split(':')
    time = int(hour)*60 + int(minute)
    
    if car not in fee_dict:
      fee_dict[car] = 0
      time_dict[car] = 0
      
    if inout == 'IN':
      car_dict[car] = time
      
    elif inout == 'OUT':
      use_time = time-car_dict[car]
      time_dict[car] += use_time
      car_dict[car] = -1
  
  for car in car_dict.keys():
    if car_dict[car] != -1:
      use_time = (23*60+59) - car_dict[car]
      time_dict[car] += use_time
  
  # print(time_dict)
  
  for car, times in time_dict.items():    
    overtime = max(times-fees[0], 0)
    fee = fees[1] + math.ceil(overtime/fees[2]) * fees[3]
    fee_dict[car] = fee

  # print(fee_dict)
  answer = [fee[1] for fee in sorted(fee_dict.items(), key=lambda x: x[0])]
  return answer

# print(solution([180, 5000, 10, 600], ["05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"]))
print(solution([1, 461, 1, 10], ["00:00 1234 IN"]))