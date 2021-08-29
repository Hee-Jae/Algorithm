#include <stdio.h>
using namespace std;
char star[3073][6145]={};

void make(int size, int x, int y){
  if(size==3){
    star[x][y+2]='*';
    star[x+1][y+1]='*';
    star[x+1][y+2]=' ';
    star[x+1][y+3]='*';
    for(int i=0; i<5; i++) star[x+2][y+i]='*';
  }
  else{
    make(size/2, x, y+size/2);
    make(size/2, x+size/2, y);
    make(size/2, x+size/2, y+size);
  }
}
int main(){
  int N;
  scanf("%d", &N);
  
  for(int i=0; i<N; i++){
    for(int j=0; j<N*2-1; j++) star[i][j] = ' ';
  }
  make(N, 0 ,0);
  for(int i=0; i<N; i++){
    for(int j=0; j<N*2-1; j++){
      printf("%c", star[i][j]);
    }
    printf("\n");
  }
}