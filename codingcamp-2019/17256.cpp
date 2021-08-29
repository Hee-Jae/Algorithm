#include <stdio.h>
using namespace std;

int main(){
  float ax,ay,az,bx,by,bz,cx,cy,cz;
  scanf("%f %f %f %f %f %f", &ax, &ay, &az, &cx, &cy, &cz);
  bx = cx-az;
  by = cy/ay;
  bz = cz-ax;
  printf("%.0f %.0f %.0f", bx, by, bz);
}