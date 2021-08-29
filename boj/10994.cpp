#include <stdio.h>
using namespace std;

char star[420][420]={};

void make(int size, int x, int y){
  if(size < 0) return;
  for(int i=0; i<size; i++) star[x][y+i] = '*';
  for(int i=1; i<size-1; i++){
    star[x+i][y] = '*';
    star[x+i][y+size-1] = '*';
  }
  for(int i=0; i<size; i++) star[x+size-1][y+i] = '*';
  make(size-4, x+2, y+2);
}
int main(){
  int N, size;
  scanf("%d", &N);
  size = 4*(N-1)+1;
  for(int i=0; i<=size; i++){
    for(int j=0; j<=size; j++) star[i][j] = ' ';
  }
  make(size, 0, 0);
  for(int i=0; i<size; i++){
    for(int j=0; j<size; j++){
      printf("%c", star[i][j]);
    }
    printf("\n");
  }
}