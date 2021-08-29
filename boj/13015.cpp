#include <stdio.h>
using namespace std;

char star[250][450]={};
int main(){
  int N;
  scanf("%d", &N);
  for(int i=0; i<=2*N-1; i++){
    for(int j=0; j<=4*N-3; j++) star[i][j] = ' ';
  }
  for(int i=0; i<N; i++) star[0][i] = '*';
  for(int i=1; i<N; i++){
    star[i][i]='*';
    star[i][i+N-1]='*';
  }

  for(int i=0; i<N; i++) star[0][3*N-3+i] = '*';
  for(int i=1; i<N; i++){
    star[i][3*N-3-i]='*';
    star[i][4*N-4-i]='*';
  }
  for(int i=0; i<N; i++) star[2*N-2][i] = '*';
  for(int i=1; i<N; i++){
    star[2*N-2-i][i]='*';
    star[2*N-2-i][i+N-1]='*';
  }
  for(int i=0; i<N; i++) star[2*N-2][3*N-3+i] = '*';
  for(int i=1; i<N; i++){
    star[2*N-2-i][3*N-3-i]='*';
    star[2*N-2-i][4*N-4-i]='*';
  }

  for(int i=0; i<2*N-1; i++){
    if(i<N){
      for(int j=0; j<4*N-3-i; j++){
        printf("%c", star[i][j]);
        // printf("*");
      }
    }
    else{
      for(int j=0; j<3*N-1+(i-N); j++){
        printf("%c", star[i][j]);
        // printf("*");
      }
    }
    printf("\n");
  }
  // for(int i=0; i<2*N-1; i++){
  //   for(int j=0; j<4*N-3; j++){
  //     printf("%c", star[i][j]);
  //   }
  //   printf("\n");
  // }
}