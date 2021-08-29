#include <stdio.h>
using namespace std;

int main(){
  double R, pi=3.14159265358979323;
  scanf("%lf", &R);
  printf("%.6lf\n", R*R*pi);
  printf("%.6lf",(R*2)*(R*2)/2);
}