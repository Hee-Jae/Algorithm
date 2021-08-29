#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define lli long long int
using namespace std;

int N,M,x,y,K,d;
int jido[25][25]={};
int dice[7]={};

void move(int dir){
  int tail;
  if(dir==4){
    x++;
    tail = dice[4];
    dice[4] = dice[3];
    dice[3] = dice[2];
    dice[2] = dice[1];
    dice[1] = tail;
    if(jido[x][y] == 0) jido[x][y] = dice[4];
    else{
      dice[4] = jido[x][y];
      jido[x][y] = 0;
    }
    cout << dice[2] << "\n";
  }

  else if(dir==3){
    x--;
    tail = dice[1];
    dice[1] = dice[2];
    dice[2] = dice[3];
    dice[3] = dice[4];
    dice[4] = tail;
    if(jido[x][y] == 0) jido[x][y] = dice[4];
    else{
      dice[4] = jido[x][y];
      jido[x][y] = 0;
    }
    cout << dice[2] << "\n";
  }

  else if(dir==1){
    y++;
    tail = dice[6];
    dice[6] = dice[2];
    dice[2] = dice[5];
    dice[5] = dice[4];
    dice[4] = tail;
    if(jido[x][y] == 0) jido[x][y] = dice[4];
    else{
      dice[4] = jido[x][y];
      jido[x][y] = 0;
    }
    cout << dice[2] << "\n";
  }

  else if(dir==2){
    y--;
    tail = dice[5];
    dice[5] = dice[2];
    dice[2] = dice[6];
    dice[6] = dice[4];
    dice[4] = tail;
    if(jido[x][y] == 0) jido[x][y] = dice[4];
    else{
      dice[4] = jido[x][y];
      jido[x][y] = 0;
    }
    cout << dice[2] << "\n";
  }
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M >> x >> y >> K;
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++) cin >> jido[i][j];
  }

  for(int i=0; i<K; i++){
    cin >> d;
    if(d==1 && y+1 >= M) continue;
    else if(d==2 && y-1 < 0) continue;
    else if(d==3 && x-1 < 0) continue;
    else if(d==4 && x+1 >= N) continue;
    move(d);
  }
}
