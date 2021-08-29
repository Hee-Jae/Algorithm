#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define lli long long int
using namespace std;

vector<vector<int> > sns(1000002);
vector<vector<int> > tree(1000002);
int adapt[1000002]={};
int visit[1000002]={};
int N,u,v;
void makeTree(int node){
  int size = sns[node].size();
  int next;
  for(int i=0; i<size; i++){
    next = sns[node][i];
    if(visit[next] == 0){
      tree[node].pb(next);
      visit[next] = 1;
      makeTree(next);
    }
  }
}

void dfs(int node){
  int size = tree[node].size();
  int next;
  if(size == 0) return;
  for(int i=0; i<size; i++){
    next = tree[node][i];
    dfs(next);
    if(adapt[next] == 0) adapt[node] = 1;
  }
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for(int i=0; i<N-1; i++){
    cin >> u >> v;
    sns[u].pb(v);
    sns[v].pb(u);
  }

  visit[1] = 1;
  makeTree(1);
  dfs(1);
  int cnt = 0;
  for(int i=1; i<=N; i++){
    if(adapt[i] == 1) cnt++;
  }
  cout << cnt;
}