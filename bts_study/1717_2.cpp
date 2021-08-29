#include <iostream>
using namespace std;

int root[1000010]={};
int find(int n){
  if(root[n] == n) return n;
  return root[n] = find(root[n]);
}
void merge(int a, int b){
  root[find(b)] = find(a);
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n,m, o,a,b;
  cin >> n >> m;

  for(int i=0; i<=n; i++) root[i] = i;

  for(int i=0; i<m; i++){
    cin >> o >> a >> b;
    if(o == 0) merge(a, b);
    else if(o == 1){
      if(find(a) == find(b)) cout << "YES\n";
      else cout << "NO\n";
    }
  }
  // for(int i=1; i<=n; i++) cout << root[i] << " ";
}