#include <stdio.h>
#include <vector>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define lli long long int
using namespace std;

int main(){
  double a,b,c,d,e,f,x,y;
  scanf("%lf %lf %lf %lf %lf %lf", &a ,&b, &c, &d, &e, &f);
  if(a==0){
    y = c/b;
    x = (f-(e*c)/b)/d;
  }
  else if(b==0){
    x = c/a;
    y = (f-(c*d)/a)/e;
  }
  else{
    c = -c;
    f = -f;
    x = (f-(c*e)/b)/((a*e)/b-d);
    y = (f-(c*d)/a)/((b*d)/a-e);
  }
  printf("%.0lf %.0lf\n",x,y);
}