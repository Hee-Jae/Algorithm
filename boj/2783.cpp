#include <stdio.h>

int main(){
  double X,Y;
  int N;
  scanf("%lf %lf", &X, &Y);
  double min = (1000/Y)*X;
  
  scanf("%d", &N);
  for(int i=0; i<N; i++){
    double xi, yi;
    scanf("%lf %lf", &xi, &yi);
    if(min > (1000/yi)*xi) min = (1000/yi)*xi;
  }
  printf("%.2lf", min);
}