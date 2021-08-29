#include <iostream>
#include <queue>
#define mp make_pair
#define fst first
#define snd second
using namespace std;
int N, M;
queue<pair<pair<int, int>, int > > red;
queue<pair<int, int> > blue;
int dir[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
char map[11][11]={};
int visit[11][2]={};

int move(int rx, int ry, int bx, int by, int dx, int dy, int cnt){
  int redhole=0, bluehole=0;
  // cout << "before : red("<<rx<<","<<ry<<"), blue("<<bx<<","<<by<<")\n";
  while(map[rx+dx][ry+dy] != '#' && map[bx+dx][by+dy] != '#'){
    rx += dx;
    ry += dy;
    bx += dx;
    by += dy;
    if(map[bx][by] == 'O') bluehole = 1;
    if(map[rx][ry] == 'O'){
      redhole = 1;
      rx = -1;
      ry = -1;
      break;
    }
    
  }
  // cout << "red("<<rx<<","<<ry<<"), blue("<<bx<<","<<by<<")\n";
  while(map[rx+dx][ry+dy] != '#' && (rx+dx!=bx || ry+dy!=by)){
    rx += dx;
    ry += dy;  
    if(map[rx][ry] == 'O'){
      redhole = 1;
      rx = -1;
      ry = -1;
      break;
    }
  }
  // cout << "red("<<rx<<","<<ry<<"), blue("<<bx<<","<<by<<")\n";
  while(map[bx+dx][by+dy] != '#' && (bx+dx!=rx || by+dy!=ry)){
    bx += dx;
    by += dy;
    if(map[bx][by] == 'O') bluehole = 1;
  }
  if(!bluehole){
    red.push(mp(mp(rx,ry),cnt+1));
    blue.push(mp(bx,by));
  }
  // cout << "after : red("<<rx<<","<<ry<<"), blue("<<bx<<","<<by<<")\n";
  if(redhole && !bluehole) return 1;
  return -3;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N >> M;
  for(int i=0; i<N; i++)
    cin >> map[i];
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      if(map[i][j] == 'R'){
        red.push(mp(mp(i,j),0));
      }
      if(map[i][j] == 'B'){
        blue.push(mp(i,j));
      }
    }
  }
  int rx, ry, bx, by, cnt=0, suc=0;
  while(1){
    if(red.empty() || blue.empty()) break;
    rx = red.front().fst.fst;
    ry = red.front().fst.snd;
    cnt = red.front().snd;
    if(cnt >= 10) break;
    bx = blue.front().fst;
    by = blue.front().snd;
    red.pop();
    blue.pop();
    // cout << "cnt : " << cnt << "\n";
    for(int i=0; i<4; i++){
      // if(i==0) cout << "down\n";
      // else if(i==1) cout << "right\n";
      // else if(i==2) cout << "up\n";
      // else if(i==3) cout << "left\n";
      suc = move(rx,ry,bx,by,dir[i][0],dir[i][1],cnt);
      // cout << "suc : " << suc << "\n";
      if(suc==1) break;
    }
    if(suc==1)break;
  }
  if(suc == 1 && cnt < 10) cout << cnt+1;
  else cout << -1;
}