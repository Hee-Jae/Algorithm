#include <stdio.h>
using namespace std;

int main(){
  int square[224]={};
  for(int i=0; i<224; i++){
    square[i] = (i+1)*(i+1);
  }
  int n, cnt=0, temp=0, index=223, min=4;
  scanf("%d", &n);
  for(int i=0; i<=222; i++){
    for(int j=0; j<=222; j++){
      for(int k=0; k<=222; k++){
        if((square[i] + square[j] + square[k]) == n){
          min = 3;
          break;
        }
      }
    }
  }
  for(int i=0; i<=222; i++){
    for(int j=0; j<=222; j++){
      if((square[i] + square[j]) == n){
        min = 2;
        break;
      }
    }
  }
  for(int i=0; i<=222; i++){
    if(n==square[i]){
      min = 1;
      break;
    }
  }
  printf("%d", min);
}