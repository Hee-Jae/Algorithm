#include <iostream>
using namespace std;

int hexagon[100][100] = {};
int cnt=0, N;
void dfs(int x, int y, int prev, int n){
  if(n>N){
    hexagon[x][y] = 0;
    return;
  }
  if(n==N && hexagon[x][y]){
    cnt++;
    hexagon[x][y] = 0;
    return;
  }
  hexagon[x][y] = 1;
  if(prev == 1){
    if(!hexagon[x-1][y+2]) dfs(x-1,y+2, 2, n+1);
    if(!hexagon[x-1][y-2]) dfs(x-1,y-2, 6, n+1);
  }
  else if(prev == 2){
    if(!hexagon[x-2][y]) dfs(x-2,y, 1, n+1);
    if(!hexagon[x+1][y+2]) dfs(x+1,y+2, 3, n+1);
  }
  else if(prev == 3){
    if(!hexagon[x-1][y+2]) dfs(x-1,y+2, 2, n+1);
    if(!hexagon[x+1][y]) dfs(x+1,y, 4, n+1);
  }
  else if(prev == 4){
    if(!hexagon[x+1][y+2]) dfs(x+1,y+2, 3, n+1);
    if(!hexagon[x+1][y-2]) dfs(x+1,y-2, 5, n+1);
  }
  else if(prev == 5){
    if(!hexagon[x+1][y]) dfs(x+1,y, 4, n+1);
    if(!hexagon[x-1][y-2]) dfs(x-1,y-2, 6, n+1);
  }
  else if(prev == 6){
    if(!hexagon[x-2][y]) dfs(x-2,y, 1, n+1);
    if(!hexagon[x+1][y-2]) dfs(x+1,y-2, 5, n+1);
  }
  hexagon[x][y] = 0;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int ans = 2;
  cin >> N;
  dfs(50,50,1,-1);
  cout << cnt;
}