#include <iostream>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N, M, nobody=1;
  int row = 0, col = 0;
  char castle[51][51]={};
  cin >> N >> M;
  for(int i=0; i<N; i++) cin >> castle[i];
  for(int i=0; i<N; i++){
    nobody = 1;
    for(int j=0; j<M; j++){
      if(castle[i][j]=='X'){
        nobody = 0;
        break;
      }
    }
    if(nobody) row ++;
  }
  for(int i=0; i<M; i++){
    nobody = 1;
    for(int j=0; j<N; j++){
      if(castle[j][i]=='X'){
        nobody = 0;
        break;
      }
    }
    if(nobody) col ++;
  }

  // int count = 0, loop;
  // if(N > M) loop = N;
  // else loop = M;
  // for(int i=0; i<loop; i++) count += police[i];
  // if(count%2==1) cout << count/2 + 1;
  // else cout << count/2;
  if(row < col) cout << col;
  else cout << row;
}