#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define lli long long int
using namespace std;

int R,C,T, room[52][52]={}, topx=-1, topy, botx, boty;
int dir[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
void clean(){
  int x,y,cnt;
  int temp[52][52]={};
  for(int i=0; i<R; i++){
    for(int j=0; j<C; j++){
      if(room[i][j] == 0 || room[i][j] == -1) continue;
      else{
        cnt = 0;
        for(int k=0; k<4; k++){
          x = i + dir[k][0];
          y = j + dir[k][1];
          if(0<=x && x<R && 0<=y && y<C && room[x][y]!=-1){
            temp[x][y] += room[i][j]/5;
            cnt ++;
          }
        }
        room[i][j] -= (room[i][j]/5)*cnt;
      }
    }
  }
  for(int i=0; i<R; i++){
    for(int j=0; j<C; j++){
      room[i][j] += temp[i][j];
    }
  }
  // cout << "----\n";
  // for(int i=0; i<R; i++){
  //   for(int j=0; j<C; j++){
  //     cout << room[i][j] << " ";
  //   }
  //   cout << "\n";
  // }
  // cout << "----\n";

  x = topx-1;
  y = topy;
  while(x>0){
    room[x][y] = room[x-1][y];
    x--;
  }
  while(y<C-1){
    room[x][y] = room[x][y+1];
    y++;
  }
  while(x<topx){
    room[x][y] = room[x+1][y];
    x++;
  }
  while(y>0){
    room[x][y] = room[x][y-1];
    y--;
  }

  x = botx+1;
  y = boty;
  while(x<R-1){
    room[x][y] = room[x+1][y];
    x++;
  }
  while(y<C-1){
    room[x][y] = room[x][y+1];
    y++;
  }
  while(x>botx){
    room[x][y] = room[x-1][y];
    x--;
  }
  while(y>0){
    room[x][y] = room[x][y-1];
    y--;
  }

  room[topx][topy+1] = 0;
  room[botx][boty+1] = 0;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> R >> C >> T;
  for(int i=0; i<R; i++){
    for(int j=0; j<C; j++){
      cin >> room[i][j];
      if(room[i][j] == -1 && topx == -1){
        topx = i;
        topy = j;
      }
      else if(room[i][j] == -1){
        botx = i;
        boty = j;
      }
    }
  }
  // cout << topx << topy << botx << boty << "\n";
  while(T--){
    
    clean();
    // cout << "\n";
    // for(int i=0; i<R; i++){
    //   for(int j=0; j<C; j++){
    //     cout << room[i][j] << " ";
    //   }
    //   cout << "\n";
    // }
    // cout << "\n";
  }
  lli cnt = 0;
  for(int i=0; i<R; i++){
    for(int j=0; j<C; j++){
      if(room[i][j] == -1) continue;
      cnt += room[i][j];
    }
  }


  cout << cnt;
}
