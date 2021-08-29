#include <stdio.h>
#include <cmath>
using namespace std;
int main(){
  int T, n,m,a,b,p,q;
  float max=0, min=1, ex;
  for(scanf("%d",&T); T; T--){
    float team[1001][2]={};
    scanf("%d %d", &n, &m);
    max = 0, min = 1;
    for(int i=0; i<m; i++){
      scanf("%d %d %d %d", &a, &b, &p, &q);
      team[a][0] += p;
      team[a][1] += q;
      team[b][0] += q;
      team[b][1] += p;
    }
    for(int i=1; i<=n; i++){
      if(team[i][0] == 0) ex = 0;
      else ex = team[i][0]*team[i][0] / ((team[i][0]*team[i][0]) + (team[i][1]*team[i][1]));
      if(ex > max) max = ex;
      if(ex < min) min = ex;
    }
    max *= 1000;
    min *= 1000;
    printf("%.0f\n%.0f\n",floor(max), floor(min));
  }
}