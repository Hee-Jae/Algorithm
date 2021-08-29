#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define lli long long int
using namespace std;
int dummy[110][110]={}, runtime=0, tx=1,ty=1,hx=1,hy=1,N;
queue<pair<int, char> > q;
queue<pair<int, int> > path;
bool move(int dir){
  if(dir==0) hy++;
  else if(dir==1) hx++;
  else if(dir==2) hy--;
  else hx--;
  // if(runtime == 13) cout << "hx : " << hx << " | hy : " << hy << "[" << dummy[hx+1][hy+1] << "]\n";
  if(hx > N || hx < 1 || hy > N || hy < 1){
    // cout << "kwang!\n";
    return false;
  }
  if(dummy[hx][hy] == 2){
    // cout << "my tail!\n";
    return false;
  }
  path.push(mp(hx,hy));
  if(dummy[hx][hy] == 1){
    // cout << "here is an apple!\n";
    dummy[hx][hy] = 2;
    return true;
  }
  dummy[hx][hy] = 2;
  tx = path.front().st;
  ty = path.front().nd;
  dummy[tx][ty] = 0;
  path.pop();
  return true;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int K,L,ax,ay, sec, dir=0;
  char chdir;
  bool gameover=false, res;
  dummy[1][1] = 2;
  path.push(mp(1,1));
  cin >> N;
  for(cin >> K; K; K--){
    cin >> ax >> ay;
    dummy[ax][ay] = 1;
  }
  for(cin >> L; L; L--){
    cin >> sec >> chdir;
    q.push(mp(sec,chdir));
  }

  sec = q.front().st;
  chdir = q.front().nd;
  q.pop();
  while(1){
    runtime++;
    res = move(dir);
    // cout << "res : " << res << "\n";
    // if(runtime == 13) cout << "res : " << res << "\n";
    if(!res){
      // cout << "dir : " << dir << "\n";
      // cout << "runtime : " << runtime << "\n";
      gameover = true;
      break;
    }
    if(gameover) break;
    if(runtime==sec){
      if(chdir=='D') dir = (dir+1)%4;
      else if(chdir=='L') dir = ((dir <= 0) ? 3 : dir-1);

      if(!q.empty()){
        sec = q.front().st;
        chdir = q.front().nd;
        q.pop();
      }
    }
  }
  cout << runtime;
}
