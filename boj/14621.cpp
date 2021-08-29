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
int root[1010]={}, college[1010]={};
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

  int N,M,u,v,d;
  char mw;
  cin >> N >> M;
  for(int i=1; i<=N; i++) root[i] = i;
  
  for(int i=1; i<=N; i++){
    cin >> mw;
    if(mw == 'M') college[i]=1;
    else college[i]=2;
  }
  for(int i=1; i<=M; i++){
    cin >> u >> v >> d;
    pq.push(mp(-d, mp(u,v)));
  }
  int cost = 0, check=0;
  while(!pq.empty()){
    u = pq.top().nd.st;
    v = pq.top().nd.nd;
    d = -pq.top().st;
    pq.pop();
    if(college[u] == college[v]) continue;
    if(find(u) == find(v)) continue;
    merge(u,v);
    cost += d;
  }
  
  for(int i=1; i<=N; i++){
    if(root[i] == i) check++;
    if(check > 1) break;
  }
  if(check > 1) cout << -1;
  else cout << cost;
}
