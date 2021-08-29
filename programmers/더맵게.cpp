#include <string>
#include <vector>
#include <iostream>
#include <queue>
#define pb push_back
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int> pq;
    int vsize = scoville.size(), fst,snd;
    for(int i=0; i<vsize; i++) pq.push(-scoville[i]);

    while(vsize > 1){
      fst = -pq.top();
      if(fst > K) break;
      pq.pop();
      snd = -pq.top();
      pq.pop();
      pq.push(-fst+snd*-2);
      vsize --;
      answer ++;
      
    }
    if(-pq.top() < K) return -1;
    return answer;
}

int main(){
  vector<int> v;
  v.pb(1);
  v.pb(1);
  v.pb(1);
  v.pb(1);
  v.pb(1);
  v.pb(1);
  int k=50;
  cout << solution(v,k) << "\n";
}