#include <iostream>
#include <queue>
#include <algorithm>
#define mp make_pair
#define st first
#define nd second
#define MAX 987654321
using namespace std;

int N,M;
int dir[4][2]={{1,0}, {0,1}, {-1,0}, {0,-1}};
int visit[1001][1001][2]={};
char map[1001][1001]={};

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  for(int i=0; i<N; i++) cin >> map[i];

  queue<pair<pair<int, int>, int> > q;
  q.push(mp(mp(0,0),1));
  visit[0][0][1]=1;
  int x, y, xx, yy, crush;
  while(!q.empty()){
    x = q.front().st.st;
    y = q.front().st.nd;
    crush = q.front().nd;
    q.pop();
    for(int i=0; i<4; i++){
      xx = x + dir[i][0];
      yy = y + dir[i][1];
      if(xx < 0 || xx >= N || yy < 0 || yy >= M) continue;
      if(map[xx][yy] == '1' && crush){
        visit[xx][yy][0] = visit[x][y][1] + 1;
        q.push(mp(mp(xx,yy),0));
      }
      else if(map[xx][yy] == '0' && visit[xx][yy][crush] == 0){
        visit[xx][yy][crush] = visit[x][y][crush] + 1;
        q.push(mp(mp(xx,yy),crush));
      }
    }
  }
  int ans;
  // cout << visit[N-1][M-1][0] << "\n";
  // cout << visit[N-1][M-1][1] << "\n";
  if(visit[N-1][M-1][0] == 0) ans = visit[N-1][M-1][1];
  else if(visit[N-1][M-1][1] == 0) ans = visit[N-1][M-1][0];
  else{
    if(visit[N-1][M-1][0] > visit[N-1][M-1][1]) ans = visit[N-1][M-1][1];
    else ans = visit[N-1][M-1][0];
  }
  if(ans != 0) cout << ans;
  else cout << -1;
}