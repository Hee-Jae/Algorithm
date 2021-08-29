#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

int makeNum(string s){
  int len = s.size(), res=0;
  if(s[2] == '-'){
    for(int i=3; i<len; i++){
      res = res*10 + (s[i]-'0');
    }
    res *= -1;
  }
  else{
    for(int i=2; i<len; i++){
      res = res*10 + (s[i]-'0');
    }
  }
  return res;
}
vector<int> solution(vector<string> operations) {
    vector<int> answer;
    int vsize = operations.size(), num, key;
    map<int, int> m;
    map<int, int> ::iterator it;
    char oper;
    for(int i=0; i<vsize; i++){
      oper = operations[i][0];
      if(oper == 'I'){
        num = makeNum(operations[i]);
        m[num] ++;
      }
      else if(oper == 'D'){
        if(m.empty()) continue;
        if(operations[i][2] == '1'){
          it = m.end();
          it--;
          key = it->first;
          if(m[key] > 1) m[key]--;
          else{
            m[key]--;
            m.erase(key);
          }
        }
        else if(operations[i][2] == '-'){
          key = m.begin()->first;
          if(m[key] > 1) m[key]--;
          else{
            m[key]--;
            m.erase(key);
          }
        } // D - operation
      } // D operation
    } // for operations
    if(m.empty()){
      answer.push_back(0);
      answer.push_back(0);
    }
    else{
      it = m.end();
      it--;
      answer.push_back(it->first);
      answer.push_back(m.begin()->first);
    }

    for(int i=0; i<2; i++) cout << answer[i] << "\n";
    return answer;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  // int T, K, num, key;
  // char order;
  // map<int, int> m;
  // map<int, int> cnt;
  // map<int, int> ::iterator it;
  vector<string> v;
  // v.push_back("I 7");
  // v.push_back("I 5");
  // v.push_back("I -5");
  // v.push_back("D -1");
  v.push_back("I 16");
  v.push_back("D 1");

  vector<int> ans = solution(v);
} // main