#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define lli long long int
using namespace std;

priority_queue<pair<int, pair<int, int> > > pq;
int root[1010]={}, C[1010][1010]={};
int find(int n){
  if(root[n] == n) return n;
  return root[n] = find(root[n]);
}
void merge(int a, int b){
  root[find(b)] = find(a);
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N,u,v,d;
  cin >> N;
  for(int i=1; i<=N; i++) root[i] = i;
  
  for(int i=1; i<=N; i++){
    for(int j=1; j<=N; j++){
      cin >> C[i][j];
    }
  }
  for(int i=1; i<=N; i++){
    for(int j=1; j<i; j++){
      pq.push(mp(-C[i][j], mp(i,j)));
    }
  }
  
  lli cost=0;
  while(!pq.empty()){
    u = pq.top().nd.st;
    v = pq.top().nd.nd;
    d = -pq.top().st;
    pq.pop();
    if(find(u) == find(v)) continue;
    merge(u,v);
    cost += d;
  }
  
  cout << cost;
}
