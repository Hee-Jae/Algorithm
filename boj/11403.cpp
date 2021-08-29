#include <iostream>
using namespace std;
int map[101][101]={};
int visit[101][101]={};
void dfs(int x, int y, int n){
  if(visit[x][y] == 1) return;
  visit[x][y] = 1;
  for(int i=0; i<n; i++){
    if(map[y][i]){
      map[x][i] = 1;
      dfs(x,i,n);
    }
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin >> N;
  for(int i=0; i<N; i++)
    for(int j=0; j<N; j++) cin >> map[i][j];
  
  for(int i=0; i<N; i++) dfs(i,i,N);

  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++) cout << map[i][j] << " ";
    cout << "\n";
  }
}