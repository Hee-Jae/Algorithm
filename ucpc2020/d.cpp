#include <iostream>
#include <cstdio>
#include <vector>
#define pb push_back

using namespace std;

int main(void){
  int n;
  scanf("%d",&n);

  vector<vector<int> > node(n+1);

  for(int i = 0 ; i < n-1 ; i++){
    int u,v;
    scanf("%d %d",&u,&v);

    node[u].pb(v);
    node[v].pb(u);
  }

  long long cnt_d = 0, cnt_g = 0;

  for(int i = 1 ; i <= n ; i++){
    if(node[i].size() >= 2){
      for(int j = 0 ; j < node[i].size() ; j++){
        int cur = node[i][j];
        if(node[cur].size() >= 2){
          cnt_d += (node[i].size()-1) * (node[cur].size() - 1);
        }
      }
      if(node[i].size() >= 3) cnt_g += node[i].size()-2;
    }
  }

  cnt_d /= 2;
  printf("d : %lld, g : %lld\n",cnt_d,cnt_g);
  cnt_g *=3;
  if(cnt_d > cnt_g) printf("D\n");
  else if(cnt_d == cnt_g) printf("DUDUDUNGA\n");
  else printf("G\n");
  return 0;
}