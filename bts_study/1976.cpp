#include <iostream>

using namespace std;

int root[202]={};

int find(int n){
  if(root[n] == n) return n;
  return root[n] = find(root[n]);
}
void merge(int a, int b){
  root[find(a)] = find(b);
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, M, r;
  int path[1001]={};
  cin >> N >> M;
  for(int i=1; i<=N; i++) root[i] = i;
  for(int i=1; i<=N; i++){
    for(int j=1; j<=N; j++){
      cin >> r;
      if(r==1) merge(i,j);
    }
  }
  for(int i=0; i<M; i++) cin >> path[i];

  int able=1, parent=find(path[0]);
  for(int i=1; i<M; i++){
    if(find(path[i]) != parent) able = 0;
  }

  if(able) cout << "YES\n";
  else cout << "NO\n";
}