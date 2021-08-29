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
queue<pair<int, int> > jq, fq;
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int R,C;
int visit[1010][1010]={}, fire[1010][1010]={};
char miro[1010][1010]={};
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> R >> C;
  for(int i=0; i<R; i++) cin >> miro[i];

  for(int i=0; i<R; i++){
    for(int j=0; j<C; j++){
      if(miro[i][j] == 'J'){
        jq.push(mp(i,j));
        visit[i][j] = 1;
      }
      else if(miro[i][j] == 'F'){
        fq.push(mp(i,j));
        fire[i][j] = 1;
      }
    }
  }

  int jx, jy, fx, fy, xx, yy, cycle=1, ans=-1, ansx, ansy;
  while(!jq.empty() || !fq.empty()){
    while(!fq.empty()){
      fx = fq.front().st;
      fy = fq.front().nd;
      // cout << "firecnt : " <<fire[fx][fy] <<"\n";
      if(fire[fx][fy] > cycle) break;
      fq.pop();
      for(int i=0; i<4; i++){
        xx = fx + dir[i][0];
        yy = fy + dir[i][1];
        if(xx < 0 || xx >= R || yy < 0 || yy >= C) continue;
        if(!fire[xx][yy] && miro[xx][yy]!='#'){
          fq.push(mp(xx,yy));
          // cout << "fire : (" << xx << "," << yy << ")\n";
          fire[xx][yy] = fire[fx][fy]+1;
        }
      }
    }
    while(!jq.empty()){
      jx = jq.front().st;
      jy = jq.front().nd;
      if(visit[jx][jy] > cycle) break;
      jq.pop();
      if(jx==0 || jx==R-1 || jy==0 || jy==C-1){
        ans = visit[jx][jy];
        ansx = jx;
        ansy = jy;
        break;
      }
      for(int i=0; i<4; i++){
        xx = jx + dir[i][0];
        yy = jy + dir[i][1];
        if(xx < 0 || xx >= R || yy < 0 || yy >= C) continue;
        if(!fire[xx][yy] && !visit[xx][yy] && miro[xx][yy]!='#'){
          jq.push(mp(xx,yy));
          // cout << "go : (" << xx << "," << yy << ")\n";
          visit[xx][yy] = visit[jx][jy]+1;
        }
      }
    }
    cycle++;
    if(ans > 0)break;
  }
  if(ans > 0) cout <<ans << "\n";
  else cout << "IMPOSSIBLE\n";
}
