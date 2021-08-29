#include <iostream>
#include <queue>
using namespace std;

int oven[300001]={};
int pizza[300001]={};
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int D,N;
  cin >> D >> N;
  for(int i=0; i<D; i++){
    cin >> oven[i];
    pq.push(make_pair(oven[i], D-i));
  }
  for(int i=0; i<N; i++) cin >> pizza[i];
  
  int p_index = 0;
  int pqindex=0;
  while(p_index < N && !pq.empty()){
    while(pizza[p_index] > pq.top().first){
      if(pq.top().second > pqindex) pqindex = pq.top().second;
      pq.pop();
      if(pq.empty()) break;
    }
    pqindex ++;
    p_index ++;
  }
  if(p_index != N || pqindex > D) cout << "0";
  else cout << D+1-pqindex;
}