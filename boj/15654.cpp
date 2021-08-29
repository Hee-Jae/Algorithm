#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
using namespace std;

vector<int> p;
int N,M;
int arr[9]={}, visit[9]={};
void dfs(int x, vector<int> v, int idx){
  v.pb(x);
  visit[idx] = 1;
  int vsize = v.size();
  if(vsize == M){
    visit[idx] = 0;
    for(int i=0; i<vsize; i++)
      cout << v[i] << " ";
    cout << "\n";
  }
  else{
    for(int i=0; i<N; i++)
      if(!visit[i]) dfs(arr[i],v,i);
  }
  visit[idx] = 0;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  for(int i=0; i<N; i++) cin >> arr[i];
  sort(arr, arr+N);

  for(int i=0; i<N; i++)
    dfs(arr[i],p,i); 
}