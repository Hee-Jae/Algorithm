#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second

using namespace std;
int dist[4001][4001]={};
int foxdist[4001]={}, wolfdist[4001]={}, wolfdist2[4001]={};
vector<vector<int> > v(4002);
int main(){
  using namespace std;
  int N, M, a,b,d;
  cin >> N >> M;
  for(int i=0; i<M; i++){
    cin >> a >> b >> d;
    v[a].pb(b);
    v[b].pb(a);
    dist[a][b] = d*2;
    dist[b][a] = d*2;
  }
  priority_queue<pair<int, pair<int, int> > > wolf;
  priority_queue<pair<int, int> > fox;

  memset(foxdist, -1, sizeof(foxdist));
  memset(wolfdist, -1, sizeof(wolfdist));
  memset(wolfdist2, -1, sizeof(wolfdist2));
  int next, cost, vtx, vsize, turn;
  wolf.push(mp(0,mp(1,1)));
  while(!wolf.empty()){
    vtx = wolf.top().snd.fst;
    cost = -wolf.top().fst;
    turn = wolf.top().snd.snd;
    wolf.pop();
    if(turn==0){
      if(wolfdist[vtx] != -1) continue;
      wolfdist[vtx] = cost;
    }
    else if(turn==1){
      if(wolfdist2[vtx] != -1) continue;
      wolfdist2[vtx] = cost;
    }   
    vsize = v[vtx].size();
    for(int i=0; i<vsize; i++){
      next = v[vtx][i];
      if(wolfdist[next] == -1){
        if(turn) wolf.push(mp(-(cost+dist[vtx][next]/2),mp(next,0)));
        else wolf.push(mp(-(cost+dist[vtx][next]*2),mp(next,1)));
      }
    }
  }

  fox.push(mp(0,1));
  while(!fox.empty()){
    vtx = fox.top().snd;
    cost = -fox.top().fst;
    fox.pop();
    if(foxdist[vtx] != -1) continue;
    foxdist[vtx] = cost;
    
    vsize = v[vtx].size();
    for(int i=0; i<vsize; i++){
      next = v[vtx][i];
      if(foxdist[next] == -1){
        fox.push(mp(-(cost+dist[vtx][next]),next));
      }
    }
  }

  int cnt = 0;
  for(int i=1; i<=N; i++) cout << foxdist[i] << " ";
  cout << "\n";
  for(int i=1; i<=N; i++) cout << wolfdist[i] << " ";
  cout << "\n";
  for(int i=1; i<=N; i++) cout << wolfdist2[i] << " ";
  cout << "\n";
  
  for(int i=1; i<=N; i++){
    if(wolfdist[i] > foxdist[i]) cnt ++;
  }
  cout << cnt;
}