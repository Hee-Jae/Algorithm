#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#define st first
#define nd second
using namespace std;

int solution(vector<vector<int> > jobs) {
    int answer = 0;
    int runtime = 0, vsize=jobs.size(), job=1;
    priority_queue<pair<int, int> > pq;
    sort(jobs.begin(), jobs.end());
    runtime = jobs[0][0] + jobs[0][1];
    answer = jobs[0][1];

    while(job < vsize){
      while(jobs[job][0] <= runtime){
        pq.push(make_pair(-jobs[job][1], job));
        job++;
        if(job >= vsize) break;
      }
      if(!pq.empty()){
        runtime += (-pq.top().st);
        answer += (runtime - jobs[pq.top().nd][0]);
        pq.pop();
        continue;
      }
      runtime++;
    }
    while(!pq.empty()){
      runtime += (-pq.top().st);
      answer += (runtime - jobs[pq.top().nd][0]);
      pq.pop();
    }
    answer /= vsize;
    return answer;
}

int main(){
  vector<vector<int> > v(4);
  v[0].push_back(0);
  v[0].push_back(10);
  v[1].push_back(4);
  v[1].push_back(10);
  v[2].push_back(5);
  v[2].push_back(11);
  v[3].push_back(15);
  v[3].push_back(2);
  cout << solution(v);
}