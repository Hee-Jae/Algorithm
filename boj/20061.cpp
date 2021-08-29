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
  if(bg==1){
    for(int i=pos-1; i>=4; i--){
      for(int j=0; j<=3; j++){
        if(board[j][i] == 0) continue;
        board[j][i+1] = board[j][i];
        board[j][i] = 0;
      }   
    }
  }
  else if(bg==2){
    for(int i=pos-1; i>=4; i--){
      for(int j=0; j<=3; j++){
        if(board[i][j] == 0) continue;
        board[i+1][j] = board[i][j];
        board[i][j] = 0;
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
          board[j][i] = 0;
        }
        bp = i;
        score ++;
      }
      if(bp!=-1){
        move(1,bp);
        remove(1);
        bp = -1;
      }
    } // blue
    
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
          board[i][j] = 0;
        }
        bp = i;
        score++;
      }
      if(bp!=-1){
        move(2,bp);
        remove(2);
        bp = -1;
      }
    } // green
  }
}

void special(int type){
  if(type==1){
    for(int i=0; i<2; i++){
      for(int j=0; j<=3; j++){
        if(board[j][5] >= 1){
          for(int j=0; j<=3; j++){
            if(board[j][9] == 0) continue;
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
    testprt();
    cout << "\n after remove \n";
    remove(1);
    remove(2);
    special(1);
    special(2);
    testprt();
  }
  cout << score << "\n";
  for(int i=0; i<10; i++){
    for(int j=0; j<10; j++){
      if(board[i][j]) blockcnt++;
    }
  }
  cout << blockcnt;
}