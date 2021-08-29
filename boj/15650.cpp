#include <iostream>
#include <vector>
#define pb push_back
using namespace std;

vector<int> p;
int N,M;
void dfs(int x, vector<int> v){
  v.pb(x);
  int vsize = v.size();
  if(vsize == M){
    for(int i=0; i<vsize; i++)
      cout << v[i] << " ";
    cout << "\n";
  }
  else for(int i=x+1; i<=N; i++) dfs(i,v);
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  for(int i=1; i<=N; i++)
    dfs(i,p); 
}