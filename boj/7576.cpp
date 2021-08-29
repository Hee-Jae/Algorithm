#include <iostream>
#include <queue>
using namespace std;

queue<pair<int, int> > q;
int tomato[1000][1000]={};
int day[1000][1000]={};
int dir[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int M, N;
  cin >> M >> N;

  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      cin >> tomato[i][j];
      if(tomato[i][j] == 1) q.push(make_pair(i,j));
    }
  }
  int x, y, xx, yy, qcount=0;
  while(!q.empty()){
    x = q.front().first;
    y = q.front().second;
    q.pop();
    for(int i=0; i<4; i++){
      xx = x + dir[i][0];
      yy = y + dir[i][1];
      if(0 <= xx && xx < N && 0 <= yy && yy < M){
        if(tomato[xx][yy] == 0){
          q.push(make_pair(xx,yy));
          tomato[xx][yy] = 1;
          qcount++;
          day[xx][yy] = day[x][y] + 1;
        }
      }
    }
  }
  // cout << "qcount : " << qcount << "\n";
  int flag = 0, count=0;
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      if(tomato[i][j] == 0){
        flag = 1;
        break;
      }
      if(day[i][j] > count) count = day[i][j];
      // cout << tomato[i][j] << " ";
    }
    if(flag) break;
    // cout << "\n";
  }
  if(flag) cout << "-1";
  else cout << count;
}