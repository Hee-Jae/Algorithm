#include <iostream>
using namespace std;

long long site[32][32]={};
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  for(int i=0; i<=30; i++){
    for(int j=0; j<=i; j++){
      if(j==0 || j==i) site[i][j] = 1;
      else site[i][j] = site[i-1][j] + site[i-1][j-1];
    }
  }
  int T;
  for(cin >> T; T; T--){
    int N,M;
    cin >> N >> M;
    cout << site[M][N] << "\n";
  }
}