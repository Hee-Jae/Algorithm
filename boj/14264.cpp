#include <stdio.h>
#include <cmath>
using namespace std;

int main(){
  double L;
  double cos30 = sqrt(3)/2, sin30=0.5;
  scanf("%lf", &L);
  printf("%.10lf", cos30*L*2 * sin30*L / 2);
}