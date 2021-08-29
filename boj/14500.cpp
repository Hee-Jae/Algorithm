#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define lli long long int
using namespace std;
int N,M, board[510][510]={};
int ans=0;
int simulation(int b0, int b1, int b2, int b3){
  int x0 = b0/4, y0 = b0%4;
  int x1 = b1/4, y1 = b1%4;
  int x2 = b2/4, y2 = b2%4;
  int x3 = b3/4, y3 = b3%4;

  int x[4]={x0,x1,x2,x3}, y[4]={y0,y1,y2,y3};
  int cx=x0,cy=y0;
  for(int i=1; i<4; i++) if(cx < x[i]) cx = x[i];
  for(int i=1; i<4; i++) if(cy < y[i]) cy = y[i];

  int sum=0, max=0;
  for(int i=0; i+cx<N; i++){
    for(int j=0; j+cy<M; j++){
      for(int k=0; k<4; k++){
        sum += board[i+x[k]][j+y[k]];
      }
      if(max < sum) max = sum;
      sum = 0;
    }
  }
  return max;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  for(int i=0; i<N; i++)
    for(int j=0; j<M; j++) cin >> board[i][j];
  
  int smlt;
  smlt = simulation(0,1,2,3);
  if(ans < smlt) ans = smlt;
  smlt = simulation(0,4,8,12);
  if(ans < smlt) ans = smlt;  
  smlt = simulation(0,1,4,5);
  if(ans < smlt) ans = smlt;
  smlt = simulation(0,1,2,4);
  if(ans < smlt) ans = smlt;
  smlt = simulation(0,1,2,6);
  if(ans < smlt) ans = smlt;
  smlt = simulation(0,1,5,9);
  if(ans < smlt) ans = smlt;
  smlt = simulation(0,4,5,6);
  if(ans < smlt) ans = smlt;
  smlt = simulation(2,4,5,6);
  if(ans < smlt) ans = smlt;
  smlt = simulation(0,4,8,9);
  if(ans < smlt) ans = smlt;
  smlt = simulation(0,1,4,8);
  if(ans < smlt) ans = smlt;
  smlt = simulation(1,5,8,9);
  if(ans < smlt) ans = smlt;
  smlt = simulation(0,4,5,9);
  if(ans < smlt) ans = smlt;
  smlt = simulation(1,4,5,8);
  if(ans < smlt) ans = smlt;
  smlt = simulation(1,2,4,5);
  if(ans < smlt) ans = smlt;
  smlt = simulation(0,1,5,6);
  if(ans < smlt) ans = smlt;
  smlt = simulation(0,1,2,5);
  if(ans < smlt) ans = smlt;
  smlt = simulation(0,4,5,8);
  if(ans < smlt) ans = smlt;
  smlt = simulation(1,4,5,6);
  if(ans < smlt) ans = smlt;
  smlt = simulation(1,4,5,9);
  if(ans < smlt) ans = smlt;
  
  cout << ans;
}
