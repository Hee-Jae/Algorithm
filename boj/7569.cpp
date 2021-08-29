#include <iostream>
#include <queue>
using namespace std;

queue<pair<int, pair<int, int> > > q;
int map[100][100][100]={};
int day[100][100][100]={};
int dir[6][3]={{1,0,0},{0,1,0},{0,0,1},{-1,0,0},{0,-1,0},{0,0,-1}};
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int M,N,H;
  cin >> M >> N >> H;
  for(int i=0; i<H; i++){
    for(int j=0; j<N; j++){
      for(int k=0; k<M; k++){
        cin >> map[i][j][k];
        if(map[i][j][k] == 1) q.push(make_pair(i, make_pair(j,k)));
      }
    }
  }
  int x,y,z,xx,yy,zz;
  while(!q.empty()){
    x = q.front().second.first;
    y = q.front().second.second;
    z = q.front().first;
    q.pop();
    for(int i=0; i<6; i++){
      xx = x + dir[i][0];
      yy = y + dir[i][1];
      zz = z + dir[i][2];
      if(0<=xx && xx<N && 0<=yy && yy<M && 0<=zz && zz<H){
        if(map[zz][xx][yy] == 0){
          q.push(make_pair(zz,make_pair(xx,yy)));
          map[zz][xx][yy] = 1;
          day[zz][xx][yy] = day[z][x][y] + 1;
        }
      }
    }
  } //while
  int flag=0, cnt=0;
  for(int i=0; i<H; i++){
    for(int j=0; j<N; j++){
      for(int k=0; k<M; k++){
        if(map[i][j][k] == 0) flag = 1;
      }
    }
  }
  for(int i=0; i<H; i++){
    for(int j=0; j<N; j++){
      for(int k=0; k<M; k++){
        if(day[i][j][k] > cnt) cnt = day[i][j][k];
      }
    }
  }
  if(flag) cout << "-1";
  else cout << cnt;
} // main