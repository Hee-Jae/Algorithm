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
int N,M, jido[10][10]={}, visit[10][10]={}, bfsjido[10][10]={};
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}}, maxarea=0;
queue<pair<int, int> > q;

void bfs(int x, int y){
  int tx, ty, xx, yy;
  q.push(mp(x,y));
  visit[x][y] = 1;
  while(!q.empty()){
    tx = q.front().st;
    ty = q.front().nd;
    bfsjido[tx][ty] = 2;
    q.pop();
    for(int i=0; i<4; i++){
      xx = tx + dir[i][0];
      yy = ty + dir[i][1];
      if(xx < 0 || xx >= N || yy < 0 || yy >= M) continue;
      if(visit[xx][yy] || bfsjido[xx][yy]==1) continue;
      q.push(mp(xx,yy));
      visit[xx][yy] = 1;
    }
  }
}

void search(){
  for(int i=0; i<N; i++)
    for(int j=0; j<M; j++) visit[i][j]=0;
  for(int i=0; i<N; i++)
    for(int j=0; j<M; j++) bfsjido[i][j]=jido[i][j];

  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      if(bfsjido[i][j]==2 && !visit[i][j]) bfs(i,j);
    }
  }
  int cnt = 0;
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      if(bfsjido[i][j]==0) cnt++;
    }
  }
  if(maxarea < cnt) maxarea = cnt;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for(int i=0; i<N; i++)
    for(int j=0; j<M; j++) cin >> jido[i][j];

  for(int i=0; i<N*M-2; i++){
    if(jido[i/M][i%M]!=0) continue;
    jido[i/M][i%M]=1;
    for(int j=i+1; j<N*M-1; j++){
      if(jido[j/M][j%M]!=0) continue;
      jido[j/M][j%M]=1;
      for(int k=j+1; k<N*M; k++){
        if(jido[k/M][k%M]!=0) continue;
        jido[k/M][k%M]=1;
        search();
        jido[k/M][k%M]=0;
      }
      jido[j/M][j%M]=0;
    }
    jido[i/M][i%M]=0;
  }
  cout << maxarea;
}