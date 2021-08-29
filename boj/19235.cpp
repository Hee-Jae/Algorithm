#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define lli long long int
using namespace std;


int board[11][11]={};
int N,t,x,y, score=0, blockcnt=0;
int groupB[10001]={}, groupG[10001]={};
int nnn=1;
void testprt(){
  for(int i=0; i<10; i++){
    for(int j=0; j<10; j++){
      if(i>=4 && j>=4) continue;
      cout << board[i][j] << " ";
    }
    cout << "\n";
  }
}
void put(int type, int px, int py){
  int tx, ty;
  tx = px;
  ty = py;
  if(type == 1){
    while(board[px][ty]==0 && ty<=9) ty++;
    board[px][ty-1] = N;
    while(board[tx][py]==0 && tx<=9) tx++;
    board[tx-1][py] = N;
  }
  else if(type == 2){
    while(board[px][ty]==0 && board[px][ty+1]==0 && ty+1<=9) ty++;
    board[px][ty-1] = N;
    board[px][ty] = N;
    while(board[tx][py]==0 && board[tx][py+1]==0 && tx<=9) tx++;
    board[tx-1][py] = N;
    board[tx-1][py+1] = N;
  }
  else if(type == 3){
    while(board[px][ty]==0 && board[px+1][ty]==0 && ty<=9) ty++;
    board[px][ty-1] = N;
    board[px+1][ty-1] = N;
    while(board[tx][py]==0 && board[tx+1][py]==0 && tx+1<=9) tx++;
    board[tx-1][py] = N;
    board[tx][py] = N;
  }
}

void move(int bg, int pos){
  int ty,tx;
  if(bg==1){
    for(int i=pos-1; i>=4; i--){
      for(int j=0; j<=3; j++){
        if(board[j][i] == 0) continue;
        ty = i;
        if(groupB[board[j][i]] == 1){
          while(ty+1<=9 && board[j][ty+1] == 0) ty++;
          board[j][ty] = board[j][i];
          board[j][i] = 0;
        }
        else if(groupB[board[j][i]] == 2){
          while(ty+1<=9 && board[j][ty+1] == 0) ty++;
          board[j][ty] = board[j][i];
          board[j][i] = 0;
          board[j][ty-1] = board[j][i-1];
          board[j][i-1] = 0;
        }
        else if(groupB[board[j][i]] == 3){
          while(ty+1<=9 && board[j][ty+1] == 0 && board[j+1][ty+1] == 0) ty++;
          board[j][ty] = board[j][i];
          board[j][i] = 0;
          board[j+1][ty] = board[j+1][i];
          board[j+1][i] = 0;
        }
      }   
    }
  }
  else if(bg==2){
    for(int i=pos-1; i>=4; i--){
      for(int j=0; j<=3; j++){
        if(board[i][j] == 0) continue;
        tx = i;
        if(groupG[board[i][j]] == 1){
          while(tx+1<=9 && board[tx+1][j] == 0) tx++;
          board[tx][j] = board[i][j];
          board[i][j] = 0;
        }
        else if(groupG[board[i][j]] == 2){
          while(tx+1<=9 && board[tx+1][j] == 0 && board[tx+1][j+1] == 0) tx++;
          board[tx][j] = board[i][j];
          board[i][j] = 0;
          board[tx][j+1] = board[i][j+1];
          board[i][j+1] = 0;
        }
        else if(groupG[board[i][j]] == 3){
          while(tx+1<=9 && board[tx+1][j] == 0) tx++;
          board[tx][j] = board[i][j];
          board[i][j] = 0;
          board[tx-1][j] = board[i-1][j];
          board[i-1][j] = 0;
        }
      }   
    }
  }
}

void remove(int type){
  int full=1, bp=-1;
  if(type==1){
    for(int i=9; i>=6; i--){
      full = 1;
      for(int j=0; j<=3; j++){
        if(board[j][i] == 0){
          full = 0;
          break;
        }
      }
      if(full){
        for(int j=0; j<=3; j++){
          if(board[j][i] == 0) continue;
          groupB[board[j][i]] = 1;
          board[j][i] = 0;
        }
        bp = i;
        score ++;
      }
    } // blue
    if(bp!=-1){
      move(1,bp);
      remove(1);
    }
  }
  else{
    for(int i=9; i>=6; i--){
      full = 1;
      for(int j=0; j<=3; j++){
        if(board[i][j] == 0){
          full = 0;
          break;
        }
      }
      if(full){
        for(int j=0; j<=3; j++){
          if(board[i][j] == 0) continue;
          groupG[board[i][j]] = 1;
          board[i][j] = 0;
        }
        bp = i;
        score++;
      }
    } // green
    if(bp!=-1){
      move(2,bp);
      remove(2);
    }
  }
}

void special(int type){
  if(type==1){
    for(int i=0; i<2; i++){
      for(int j=0; j<=3; j++){
        if(board[j][5] >= 1){
          for(int j=0; j<=3; j++){
            if(board[j][9] == 0) continue;
            groupB[board[j][9]] = 1;
            board[j][9] = 0; 
          }
          move(1,9);
          remove(1);
          break;
        }
      }
    }
  }
  else{
    for(int i=0; i<2; i++){
      for(int j=0; j<=3; j++){
        if(board[5][j] >= 1){
          for(int j=0; j<=3; j++){
            if(board[9][j] == 0) continue;
            groupG[board[9][j]] = 1;
            board[9][j] = 0; 
          }
          move(2,9);
          remove(2);
          break;
        }
      }
    }
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  for(cin>>N; N; N--){
    cin >> t >> x >> y;
    put(t,x,y);
    groupB[N] = t;
    groupG[N] = t;
    remove(1);
    remove(2);
    special(1);
    special(2);

  }
  cout << score << "\n";
  for(int i=0; i<10; i++){
    for(int j=0; j<10; j++){
      if(board[i][j]) blockcnt++;
    }
  }
  cout << blockcnt;
}