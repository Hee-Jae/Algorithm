#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define lli long long int
using namespace std;
map<lli, lli> visit;
queue<pair<lli,int> > q;
lli goal=0;
vector<vector<int> > dir(10);
void init(){
  dir[1].pb(2); dir[1].pb(4);
  dir[2].pb(1); dir[2].pb(3); dir[2].pb(5);
  dir[3].pb(2); dir[3].pb(6);
  dir[4].pb(1); dir[4].pb(5); dir[4].pb(7);
  dir[5].pb(2); dir[5].pb(4); dir[5].pb(6); dir[5].pb(8);
  dir[6].pb(3); dir[6].pb(5); dir[6].pb(9);
  dir[7].pb(4); dir[7].pb(8);
  dir[8].pb(5); dir[8].pb(7);dir[8].pb(9);
  dir[9].pb(6); dir[9].pb(8);
}
lli bitswap(lli data, int prev, int next){
  lli remover1=15, remover2=15, tmp1=15, tmp2=15;
  tmp1 = (data >> (9-prev)*4)&tmp1;
  tmp2 = (data >> (9-next)*4)&tmp2;
  remover1 = remover1 << (9-prev)*4;
  remover2 = remover2 << (9-next)*4;
  data = data & ~remover1;
  data = data & ~remover2;
  data = data | (tmp1 << (9-next)*4);
  data = data | (tmp2 << (9-prev)*4);
  return data;
}
int main(){
  for(int i=1; i<=8; i++){
    goal += i;
    goal = goal << 4;
  }
  init();
  lli start=0, n, s, next;
  for(int i=1; i<=9; i++){
    scanf("%lld", &n);
    if(n==0) s = i;
    start = start << 4;
    start += n;
  }
  visit[start]=1;
  q.push(mp(start,s));
  while(!q.empty()){
    n = q.front().st;
    s = q.front().nd;
    if(n==goal) break;
    q.pop();
    for(int i=0; i<dir[s].size(); i++){
      next = bitswap(n,s,dir[s][i]);
      if(visit[next]==0){
        q.push(mp(next,dir[s][i]));
        visit[next] = visit[n]+1;
      }
    }
  }
  if(visit[goal]==0) printf("-1");
  else printf("%lld\n", visit[goal]-1);
}