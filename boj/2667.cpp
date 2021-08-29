#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int dir[4][2]={{1,0}, {0,1}, {-1,0}, {0,-1}};
char map[26][26]={};
int group[676]={};
int idx=0, N;

void prt(){
  cout << "\n";
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      cout << map[i][j];
    }
    cout << "\n";
  }
  // cout << "\n";
}
void bfs(int x, int y){
  queue<pair<int, int> > q;
  q.push(make_pair(x,y));
  int xx,yy, cnt=1;
  map[x][y] = '0';
  while(!q.empty()){
    x = q.front().first;
    y = q.front().second;
    // map[x][y] = '0';
    // prt();
    // cout << "\n" << cnt << "\n";
    q.pop();
    for(int i=0; i<4; i++){
      xx = x + dir[i][0];
      yy = y + dir[i][1];
      if(0 <= xx && xx < N && 0 <= yy && yy < N && map[xx][yy]=='1'){
        q.push(make_pair(xx,yy));
        map[xx][yy]='0';
        cnt ++;
        // prt();
        // cout << "\n" << cnt << "\n";
      }
    }
  }
  group[idx++] = cnt;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for(int i=0; i<N; i++) cin >> map[i];
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      if(map[i][j]=='1') bfs(i,j);
    }
  }
  sort(group, group+idx);
  cout << idx << "\n";
  for(int i=0; i<idx; i++) cout << group[i] << "\n";
}