#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#define pb push_back
#define mp make_pair

using namespace std;

int tim[200001], num[200001];

int main(void){
  int n;
  scanf("%d",&n);

  vector<vector<int> > node(n+1);

  for(int i = 1 ; i <= n ; i++){
    int temp;
    scanf("%d",&temp);
    while(temp != 0){
      node[i].pb(temp);
      scanf("%d",&temp);
    }
  }

  int m;
  scanf("%d",&m);

  queue<pair<int,int> > que;
  memset(tim,-1,sizeof(tim));
  memset(num,0,sizeof(num));

  for(int i = 0 ; i < m ; i++){
    int tmp;
    scanf("%d",&tmp);
    tim[tmp] = 0;
    num[tmp] = 1;
    que.push(mp(tmp,0));
  }

  while(!que.empty()){
    int cur = que.front().first;
    int cur_time = que.front().second;
    que.pop();
    for(int i = 0 ; i < node[cur].size() ; i++){
      int next = node[cur][i];
      if(tim[next] == -1){
        num[next]++;
        if(num[next] >= (node[next].size()+1)/2){
          tim[next] = cur_time+1;
          que.push(mp(next,tim[next]));
        }
      }
    }
  }

  for(int i = 1 ; i <= n ; i++) printf("%d ",tim[i]);
  printf("\n");
  return 0;
}
