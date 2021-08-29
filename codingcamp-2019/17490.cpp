#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
long long rock;
int dong[1000002]={};
// priority_queue< pair<int, int>, vector< pair<int, int> >, less< pair<int, int> > > pq;
priority_queue<int, vector<int>, greater<int> > pq;
queue<int> q;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N,M,ii,jj;
  long long K;
  cin >> N >> M >> K;
  for(int i=1; i<=N; i++){
    cin >> rock;
    q.push(rock);
  }
  for(int i=1; i<=M; i++){
    cin >> ii >> jj;
    if(abs(ii-jj) > 1) dong[N] = 1;
    else dong[min(ii,jj)] = 1;
  }
  
  long long count = 0;
  int start=0;
  for(int i=1; i<=N; i++){
    if(dong[i] == 1){
      start = i;
      break;
    }
  }
  for(int i=1; i<=start; i++){
    q.push(q.front());
    q.pop();
  }
  int i = start;
  while(!q.empty()){
    pq.push(q.front());
    q.pop();
    i++;
    if(i == N+1) i = 1;
    if(dong[i] == 1){
      count += pq.top();
      while(!pq.empty()) pq.pop();
    } 
  }
  // cout << "count : "<<count << "\n"; 
  if(K >= count || M == 0 || M == 1) cout << "YES";
  else cout << "NO";
}