#include <iostream>
#include <queue>
using namespace std;

int F,S,G,U,D;
int visit[1000002]={};
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> F >> S >> G >> U >> D;

  int x, stair=1;
  for(int i=0;i <=1000000; i++) visit[i] = -1;
  queue<int> q;
  q.push(S);
  visit[S] = 0;
  while(!q.empty()){
    x = q.front();
    q.pop();
    if(x == G){
      stair = 0;
      break;
    }
    if(x+U <= F && visit[x+U] == -1){
      q.push(x+U);
      visit[x+U] = visit[x]+1;
    }
    if(x-D >= 1 && visit[x-D] == -1){
      q.push(x-D);
      visit[x-D] = visit[x]+1;
    }
  }
  if(stair) cout << "use the stairs\n";
  else cout << visit[x];
}