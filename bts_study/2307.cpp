#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
using namespace std;
vector<vector<int> >v(1002);
vector<pair<int, int> > way;
int N,M;
int path[1002]={}, dist[1002]={};
int originDist[1002][1002]={};
int dijkstra(){
  int cost, vtx, next, vsize, prev;
  priority_queue<pair<int, pair<int, int> > > pq;
  pq.push(mp(0, mp(1,0)));
  while(!pq.empty()){
    vtx = pq.top().snd.fst;
    prev = pq.top().snd.snd;
    cost = -pq.top().fst;
    // cout << "vtx : "<< vtx << " | " << "prev : " << prev << " | " <<"cost : " << cost << "\n";
    pq.pop();
    if(dist[vtx] != -1) continue;
    dist[vtx] = cost;
    path[vtx] = prev;
    vsize = v[vtx].size();
    // cout << "size : " << vsize << " | " << "vtx : " << vtx << "\n";
    for(int i=0; i<vsize; i++){
      next = v[vtx][i];
      // cout << "next : " << next << " | " << "vtx : " << vtx << "\n";
      if(dist[next]==-1 && originDist[vtx][next] != -1)
        // cout << "next : " << next << " | " << "vtx : " << vtx << "\n";
        pq.push(mp(-(cost+originDist[vtx][next]),mp(next,vtx)));
    }
  }
  return dist[N];
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int a,b,t, time, wayIdx=0;
  cin >> N >> M;
  for(int i=0; i<M; i++){
    cin >> a >> b >> t;
    v[a].pb(b);
    v[b].pb(a);
    originDist[a][b] = t;
    originDist[b][a] = t;
  }
  memset(dist,-1,sizeof(dist));
  time = dijkstra();
  int start = N, end = path[N];
  while(1){
    if(end == 1){
      way.pb(mp(start,end));
      break;
    }
    way.pb(mp(start,end));
    start = end;
    end = path[end];
  }
  // for(int i=1; i<=N; i++) cout << dist[i] << " ";
  // cout << "\n";
  // for(int i=1; i<=N; i++) cout << path[i] << " ";
  // for(int i=0; i<way.size(); i++) cout << way[i].fst << " | " << way[i].snd << "\n";
  // cout << "time : " << time << "\n";
  
   
  int originTime, waySize=way.size();
  int vsize, max=-1, newtime, flag=0;
  for(int i=0; i<waySize; i++){
    memset(dist,-1,sizeof(dist));
    start = way[i].snd;
    end = way[i].fst;
    originTime = originDist[start][end];
    originDist[start][end] = -1;
    originDist[end][start] = -1;

    newtime = dijkstra();
    if(newtime == -1) flag = 1;
    // for(int i=1; i<=N; i++) cout << dist[i] << " ";
    // cout << "\n";
    // cout << "newtime : " << newtime << "\n";
    if(max < (newtime-time)) max = (newtime-time);
    originDist[start][end] = originTime;
    originDist[end][start] = originTime;
  }
  if(flag) cout << "-1";
  else cout << max;
}