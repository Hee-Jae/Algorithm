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
int N, sea[25][25]={}, movecnt[25][25]={}, baby=2, dist=0, ate=0,sx,sy;
int dir[4][2] = {{-1,0},{0,-1},{0,1},{1,0}};
queue<pair<int, int> > q;
priority_queue<pair<int, int> > pq;
int find(int x, int y){
  while(!pq.empty()) pq.pop();
  while(!q.empty()) q.pop();
  int visit[25][25]={};
  int tx,ty,xx,yy, eat=0, mindist=1000;
  movecnt[x][y] = 0;
  q.push(mp(x,y));
  visit[x][y] = 1;
  while(!q.empty()){
    tx = q.front().st;
    ty = q.front().nd;
    if(movecnt[tx][ty] > mindist) break;
    q.pop();
    for(int i=0; i<4; i++){
      xx = tx + dir[i][0];
      yy = ty + dir[i][1];
      if(xx < 0 || xx >= N || yy < 0 || yy >= N) continue;
      if(baby < sea[xx][yy] || visit[xx][yy]) continue;
      if(sea[xx][yy] != 0 && sea[xx][yy] < baby){
        mindist = movecnt[tx][ty];
        pq.push(mp(-xx,-yy));
      }
      q.push(mp(xx,yy));
      visit[xx][yy] = 1;
      movecnt[xx][yy] = movecnt[tx][ty]+1;
    }
  }
  if(!pq.empty()){
    tx = -pq.top().st;
    ty = -pq.top().nd;
    sea[tx][ty] = 9;
    sea[x][y] = 0;
    dist += (movecnt[tx][ty]);
    ate++;
    if(baby == ate){
      baby++;
      ate = 0;
    }
    sx = tx;
    sy = ty;
  }
  // cout << "\n-dist : " << dist << "-\n";
  // for(int i=0; i<N; i++){
  //   for(int j=0; j<N; j++){
  //     cout << sea[i][j] << " ";
  //   }
  //   cout << "\n";
  // }
  return mindist;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      cin >> sea[i][j];
      if(sea[i][j]==9){
        sx = i;
        sy = j;
      }
    }
  }
  while(find(sx,sy)!=1000){
    continue;
    // cout << "baby : " << baby << "\n";
    // cout << "sx : " << sx << " | sy : " << sy << "\n";
  }
  // cout << "--\n";
  // for(int i=0; i<N; i++){
  //   for(int j=0; j<N; j++){
  //     cout << sea[i][j] << " ";
  //   }
  //   cout << "\n";
  // }
  cout << dist;
}
