#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstdlib>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define lli long long int
using namespace std;

priority_queue<pair<int, pair<int, int> > > pq;
vector<pair<int, int> > key;
queue<pair<int, int> > q;
int root[260]={}, dir[4][2]={{1,0}, {0,1}, {-1,0}, {0,-1}}, visit[60][60]={}, keymap[60][60]={};
char miro[60][60]={};
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

  int N,M,u,v,d, sx,sy,x,y,xx,yy, number=1;
  cin >> N >> M;
  for(int i=1; i<=M+1; i++) root[i] = i;
  
  for(int i=0; i<N; i++) cin >> miro[i];
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      if(miro[i][j] == 'S' || miro[i][j] == 'K'){
        key.pb(mp(i,j));
        keymap[i][j] = number++; 
      }
    }
  }
  // for(int i=0; i<N; i++){
  //   for(int j=0; j<N; j++){
  //     cout << keymap[i][j];
  //   }
  //   cout << "\n";
  // }
  int keysize = key.size();
  for(int i=0; i<keysize; i++){

    for(int j=0; j<N; j++){
      for(int k=0; k<N; k++) visit[j][k]=0;
    }

    q.push(mp(key[i].st, key[i].nd));
    while(!q.empty()){
      x = q.front().st;
      y = q.front().nd;
      if(keymap[x][y] > 0){
        pq.push(mp(-visit[x][y], mp(keymap[key[i].st][key[i].nd], keymap[x][y])));
      }
      q.pop();
      for(int i=0; i<4; i++){
        xx = x + dir[i][0];
        yy = y + dir[i][1];
        if(xx < 0 || xx >= N || yy < 0 || yy >= N) continue;
        if(visit[xx][yy] > 0 || miro[xx][yy] == '1') continue;
        visit[xx][yy] = visit[x][y]+1;
        q.push(mp(xx,yy));
      }
    }
  }
  
  lli cost=0;
  while(!pq.empty()){
    u = pq.top().nd.st;
    v = pq.top().nd.nd;
    d = -pq.top().st;
    pq.pop();
    if(u==v) continue;
    if(find(u) == find(v)) continue;
    // cout << "u " << u << " | v : " << v << "\n";
    merge(u,v);
    cost += d;
  }

  int check = 0;
  for(int i=1; i<number; i++){
    // cout << root[i] << " ";
    if(root[i] == i) check++;
    if(check > 1) break;
  }
  if(check > 1) cout << -1;
  else cout << cost;
}
