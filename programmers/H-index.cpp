#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> citations) {
    int answer = -1, vsize = citations.size();
    int cnt, h;
    sort(citations.begin(), citations.end());
    h = citations[vsize-1];
    for(int i=vsize-1; i>=0; i--){
      cnt = vsize - i;
      while(citations[i] < h){
        // cout << h << "\n";
        h--;
        if(cnt >= h){
          if(citations[i] < h) answer = cnt-1;
          else answer = cnt;
          break;
        }
      }
      if(answer != -1) break;
    }
    if(answer == -1){
      while(cnt < h) h--;
      answer = h;
    }
    return answer;
}

int main(){
  vector<int> v;
  v.push_back(3);
  v.push_back(0);
  v.push_back(6);
  v.push_back(1);
  v.push_back(5);
  cout << solution(v);
}