#include <stdio.h>
using namespace std;

int wheel[5][10]={}, K, l, d;

void move(int label, int dir){
  int tail;
  if(dir==1){
    tail = wheel[label][7];
    for(int i=7; i>0; i--) wheel[label][i] = wheel[label][i-1];
    wheel[label][0] = tail;
  }
  else if(dir==-1){
    tail = wheel[label][0];
    for(int i=1; i<8; i++) wheel[label][i-1] = wheel[label][i];
    wheel[label][7] = tail;
  }
}

bool letsmove[4];
void comp(){
  if(wheel[0][2] == wheel[1][6]) letsmove[0] = false;
  else letsmove[0] = true;
  if(wheel[1][2] == wheel[2][6]) letsmove[1] = false;
  else letsmove[1] = true;
  if(wheel[2][2] == wheel[3][6]) letsmove[2] = false;
  else letsmove[2] = true;
}

void ptr(){
  for(int i=0; i<4; i++){
    for(int j=0; j<8; j++) printf("%d " , wheel[i][j]);
    printf("\n");
  }
}
int main(){
  for(int i=0; i<4; i++){
    for(int j=0; j<8; j++) scanf("%1d", &wheel[i][j]);
  }
  // printf("---init---\n");
  // ptr();
  scanf("%d", &K);
  for(int i=0; i<K; i++){
    scanf("%d %d", &l, &d);
    comp();
    move(l-1, d);
    if(l==1){
      if(letsmove[0]){
        move(1, -1*d);
        if(letsmove[1]){
          move(2, d);
          if(letsmove[2]) move(3, -1*d);
        }
      }
    }
    else if(l==2){
      if(letsmove[0]) move(0, -1*d);
      if(letsmove[1]){
        move(2, -1*d);
        if(letsmove[2]) move(3, d);
      }
    }
    else if(l==3){
      if(letsmove[1]){
        move(1, -1*d);
        if(letsmove[0]){
          move(0, d);
        }
      }
      if(letsmove[2]) move(3, -1*d);
    }
    else if(l==4){
      if(letsmove[2]){
        move(2, -1*d);
        if(letsmove[1]){
          move(1, d);
          if(letsmove[0]) move(0, -1*d);
        }
      }
    }
    // printf("---%d---\n", i);
    // ptr();
  }
  int score=0;
  if(wheel[0][0]) score += 1;
  if(wheel[1][0]) score += 2;
  if(wheel[2][0]) score += 4;
  if(wheel[3][0]) score += 8;
  printf("%d\n", score);
}