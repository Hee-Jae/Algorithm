#include <iostream>
#include <vector>
#define pb push_back
using namespace std;

vector<vector<int> > v(100002);
int root[100002]={}, visit[100002]={};
int N,a,b;

void dfs(int node, int parent){
  root[node] = parent;
  visit[node] = 1;
  int size = v[node].size();
  int next;
  for(int i=0; i<size; i++){
    next = v[node][i];
    if(!visit[next]) dfs(v[node][i], node);
  }
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N;
  for(int i=1; i<=N-1; i++){
    cin >> a >> b;
    v[a].pb(b);
    v[b].pb(a);
  }
  
  dfs(1,1);
  for(int i=2; i<=N; i++) cout << root[i] << "\n";
}