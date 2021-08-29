def solution(s):
    answer = ''
    dict = {'z':[(0,3)], 'o':[(1,2)], 't':[(2,1), (3,3)], 'f':[(4,2),(5,2)], 's':[(6,1),(7,3)], 'e':[(8,4)], 'n':[(9,3)]}
    size = len(s)
    i = 0
    while(i < size):
      
      if(s[i] in dict):
        key = s[i]
        if(len(dict[key]) > 1):
          i+=1
          if(key == 't' and s[i] == 'w'):
            answer += str(dict[key][0][0])
            i += dict[key][0][1]
          elif(key == 't' and s[i] == 'h'):
            answer += str(dict[key][1][0])
            i += dict[key][1][1]
          elif(key == 'f' and s[i] == 'o'):
            answer += str(dict[key][0][0])
            i += dict[key][0][1]
          elif(key == 'f' and s[i] == 'i'):
            answer += str(dict[key][1][0])
            i += dict[key][1][1]
          elif(key == 's' and s[i] == 'i'):
            answer += str(dict[key][0][0])
            i += dict[key][0][1]
          elif(key == 's' and s[i] == 'e'):
            answer += str(dict[key][1][0])
            i += dict[key][1][1]
        else:
          answer += str(dict[key][0][0])
          i += dict[key][0][1]
      else:
        answer += s[i]
      
      i+=1
    answer = int(answer)
    return answer

# s = "one4seveneight"
# s = "23four5six7"
# s = "onetwothreefourfivesixseven0eight0nine0"
# s = "1sixsevensixsevensixseven0"
s = "2000000000"
print(solution(s))