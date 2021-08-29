#include <stdio.h>
#include <math.h>
using namespace std;
void move(int n, int x, int y, int z){
  if(n==1) printf("%d %d\n",x,z);
  else{
    move(n-1,x,z,y);
    printf("%d %d\n",x,z);
    move(n-1,y,x,z);
  }
}

int main(){
  int N;  
  scanf("%d", &N);
  printf("%d\n", (int)pow(2,N)-1);
  move(N,1,2,3);
}