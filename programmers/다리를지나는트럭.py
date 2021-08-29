def solution(bridge_length, weight, truck_weights):
    queue = []
    seconds = 1
    total_weights = 0
    for truck in truck_weights:
      if not queue:
        queue.append((truck, seconds))
        total_weights += truck
      else:
        if(total_weights+truck <= weight):
          seconds += 1
          queue.append((truck, seconds))
          total_weights += truck
        else:
          while(total_weights+truck > weight):
            seconds = queue[0][1]+bridge_length
            if(queue[0][1]+bridge_length > queue[-1][1]): seconds = queue[0][1]+bridge_length
            else: seconds = queue[-1][1]+1
            total_weights -= queue[0][0]
            queue.pop(0)
          queue.append((truck, seconds))
          total_weights += truck

    if queue:
      seconds = queue[-1][1]+bridge_length

    answer = seconds
    
    return answer

bridge_length = 100
weight = 100
truck_weights = [10,10,10,10,10,10,10,10,10,10]
solution(bridge_length, weight, truck_weights)