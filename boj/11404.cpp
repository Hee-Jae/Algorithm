#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define lli long long int
#define INF 987654321
using namespace std;

int n,m,a,b,c;
int w[102][102]={};

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i=1; i<=n; i++)
    for(int j=1; j<=n; j++) w[i][j] = INF;

  for(cin >> m; m; m--){
    cin >> a >> b >> c;
    if(w[a][b] > c) w[a][b] = c;
  }
  
  for(int k=1; k<=n; k++){
    for(int i=1; i<=n; i++){
      for(int j=1; j<=n; j++){
        if(w[i][k] + w[k][j] < w[i][j]) w[i][j] = w[i][k]+w[k][j];
      }
    }
  }
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      if(w[i][j]==INF || i==j) cout << 0 << " ";
      else cout << w[i][j] << " ";
    }
    cout << "\n";
  }
  
}
