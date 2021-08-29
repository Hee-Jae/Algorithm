#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define lli long long int
using namespace std;
int n,m,t,a,b,k;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  for(cin>>t; t; t--){
    cin >> n;
    int rank[502]={}, origin[502]={};
    for(int i=n-1; i>=0; i--){
      cin >> k;
      origin[k] = i;
      rank[k] = i;
    }
    for(cin>>m; m; m--){
      cin >> a >> b;
      if(origin[a] > origin[b]){
        rank[a] --;
        rank[b] ++;
      }
      else{
        rank[a] ++;
        rank[b] --;
      }
    }
    int check[502]={}, imp=0;
    for(int i=1; i<=n; i++){
      if(check[rank[i]]==0) check[rank[i]]=i;
      else{
        imp = 1;
        break;
      }
    }
    if(imp) cout << "IMPOSSIBLE\n";
    else{
      for(int i=n-1; i>=0; i--) cout << check[i] << " ";
      cout << "\n";
    }
  }
}
