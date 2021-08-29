#include <stdio.h>
using namespace std;

int main(){
  double pi=3.141592;
  double d1, d2;
  scanf("%lf %lf", &d1, &d2);
  printf("%.6lf", d1*2 + d2*2*pi);
}