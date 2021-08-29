#include <stdio.h>
int main(){
  int T;
  scanf("%d", &T);
  int A,B,C, temp;
  temp = T;
  A = temp/300;
  temp = temp%300;
  B = temp/60;
  temp = temp%60;
  C = temp/10;
  if(A*300 + B*60 + C*10 == T) printf("%d %d %d", A,B,C);
  else printf("-1");
}