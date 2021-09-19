#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> enter, vector<int> leave) {
  vector<int> answer(enter.size());
  set<int> room;
  map<int, int> guest;
  set<int> ::iterator leaveTarget;
  map<int, int> ::iterator guestIter;
  int lidx = 0;
  for(int i=0; i<enter.size(); i++){
    for(guestIter=guest.begin(); guestIter!=guest.end(); guestIter++){
      guestIter->second += 1;
    }

    guest[enter[i]] = room.size();
    room.insert(enter[i]);
    while(true){
      leaveTarget = room.find(leave[lidx]);
      if(leaveTarget == room.end() or lidx >= leave.size()) break;
      room.erase(leaveTarget);
      answer[leave[lidx]-1] = guest[leave[lidx]];
      lidx ++;
    }
  }
  return answer;
}

int main(){
  vector<int> enter = {1,4,2,3};
  vector<int> leave = {2,1,3,4};
  vector<int> answer;
  answer = solution(enter, leave);
  for(int i=0; i<answer.size(); i++){
    cout << answer[i] << " ";
  }
}