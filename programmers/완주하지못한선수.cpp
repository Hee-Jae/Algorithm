#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
  map<string, int> m;
  map<string, int> ::iterator iter;
  string answer = "";
  for(int i=0; i<participant.size(); i++){
    if(m.find(participant[i]) == m.end()){
      m[participant[i]] = 1;
    } else{
      m[participant[i]] += 1;
    }
  }

  for(int i=0; i<completion.size(); i++){
    m[completion[i]] -= 1;
  }

  for(iter=m.begin(); iter!=m.end(); iter++){
    if(iter->second != 0){
      answer = iter->first;
    }
  }
  return answer;
}