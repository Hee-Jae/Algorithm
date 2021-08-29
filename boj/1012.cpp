#include <iostream>
#include <queue>
using namespace std;
int dir[4][2]={{1,0}, {0,1}, {-1,0}, {0,-1}};
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T, cnt=0;
  for(cin>>T; T; T--){
    queue<pair<int,int> > q;
    int map[51][51]={};
    int M,N,K,X,Y;
    int cx, cy, tx, ty;
    cnt = 0;
    cin >> M >> N >> K;
    for(int i=0; i<K; i++){
      cin >> X >> Y;
      map[Y][X] = 1;
    }
    for(int i=0; i<N; i++){
      for(int j=0; j<M; j++){
        if(map[i][j] == 1){
          while(!q.empty()) q.pop();
          cnt ++;
          q.push(make_pair(i,j));
          map[i][j] = 0;
          while(!q.empty()){
            cx = q.front().first;
            cy = q.front().second;
            q.pop();
            for(int k=0; k<4; k++){
              tx = cx + dir[k][0];
              ty = cy + dir[k][1];
              if(0<= tx && tx < N && 0<= ty && ty < M){
                if(map[tx][ty] == 1){
                  q.push(make_pair(tx, ty));
                  map[tx][ty]=0;
                }
              }
            } // dir
          } // while q not empty
        } // if map = 1
      } // j
    } // i
    cout << cnt << "\n";
  } // T
}