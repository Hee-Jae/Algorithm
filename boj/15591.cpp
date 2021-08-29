#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define lli long long int
#define INF 1000000010
using namespace std;

vector<vector<int > > usado(5010);
queue<int> que;
int edge[5010][5010]={};

void search(int start, int node, int prev, int cost){
  int size = usado[node].size();
  int next;
  edge[start][node] = cost;
  for(int i=0; i<size; i++){
    next = usado[node][i];
    if(next == prev) continue;
    if(edge[node][next] < cost) search(start, next, node, edge[node][next]);
    else search(start, next, node, cost);
  }
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N,Q,p,q,r,k,v;
  cin >> N >> Q;
  for(int i=0; i<N-1; i++){
    cin >> p >> q >> r;
    usado[p].pb(q);
    usado[q].pb(p);
    edge[p][q] = r;
    edge[q][p] = r;
  }
  
  
  for(int i=1; i<=N; i++){
    search(i, i, 0, INF);
  }
  int cnt;
  for(int i=0; i<Q; i++){
    cin >> k >> v;
    cnt = 0;
    for(int j=1; j<=N; j++){
      if(edge[v][j] == INF) continue;
      if(edge[v][j] >= k) cnt++;
    }
    cout << cnt << "\n";
  }

  // for(int i=1; i<=N; i++){
  //   for(int j=1; j<=N; j++){
  //     cout << edge[i][j] << " ";
  //   }
  //   cout << "\n";
  // }
}
