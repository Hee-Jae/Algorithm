#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define lli long long int
#define INF 1e18
using namespace std;

int N,M;
lli dist[510]={};
vector<pair<int, int> > v[510];
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int A,B,C,vsize, next, d;
  bool negCycle = false;
  cin >> N >> M;
  for(int i=0; i<M; i++){
    cin >> A >> B >> C;
    v[A].pb(mp(B,C));
  }
  fill(dist+1,dist+N+1,INF);
  dist[1] = 0;
  for(int i=1; i<=N; i++){
    for(int j=1; j<=N; j++){
      vsize = v[j].size();
      for(int k=0; k<vsize; k++){
        next = v[j][k].st;        
        d = v[j][k].nd;
        if(dist[j] != INF && dist[next] > d + dist[j]){
          dist[next] = d + dist[j];
          if(i == N){
            negCycle = true;
            break;
          }
        }
      }
    }
  }
  if(negCycle) cout << -1;
  else{
    for(int i=2; i<=N; i++){
      if(dist[i] == INF) cout << -1 << "\n";
      else cout << dist[i] << "\n";
    }
  }
}
