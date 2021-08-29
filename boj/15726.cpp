#include <stdio.h>
#include <cmath>
using namespace std;

int main(){
  double A,B,C;
  scanf("%lf %lf %lf", &A, &B, &C);
  double s1 = floor((A*B)/C);
  double s2 = floor((A/B)*C);
  if(s1 > s2) printf("%.0lf", s1);
  else printf("%.0lf", s2);
}