#include <stdio.h>
using namespace std;

char star[500][500]={};

void make(int s){
  for(int i=0; i<3; i++) star[s*2+1-i][s*2-1] = '*';
  int x = s*2-1;
  int y = s*2-1;

  for(int size=2; size<=s; size++){
    for(int i=0; i<2; i++) star[x][++y] = '*';
    for(int i=0; i<4*(size-1)+1; i++) star[x++][y] = '*';
    x--;
    for(int i=0; i<4*(size-1)+1; i++) star[x][y--] = '*';
    y++;
    for(int i=0; i<4*(size-1)+3; i++) star[x--][y] = '*';
    x++;
    for(int i=0; i<4*(size-1)+1; i++) star[x][y++] = '*';
    y--;
  }
}
int main(){
  int N;
  scanf("%d", &N);
  if(N==1) printf("*\n");
  else{
    for(int i=1; i<=4*N-1; i++){
      for(int j=1; j<=4*N-3; j++) star[i][j] = ' ';
    }
    make(N);
    for(int i=1; i<=4*N-1; i++){
      for(int j=1; j<=4*N-3; j++){
        if(i==2){
          printf("%c", star[i][1]);
          break;
        }
        printf("%c", star[i][j]);
      }
      printf("\n");
    }
  }
}