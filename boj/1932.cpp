#include <iostream>
#include <algorithm>
using namespace std;
int tri[501][501]={};
int dp[501][501]={};
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for(int i=0; i<n; i++){
    for(int j=0; j<=i; j++) cin >> tri[i][j];
  }
  dp[0][0] = tri[0][0];
  for(int i=1; i<n; i++){
    for(int j=0; j<=i; j++){
      if(j==0) dp[i][j] = dp[i-1][j] + tri[i][j];
      else if(j==i) dp[i][j] = dp[i-1][j-1] + tri[i][j];
      else dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + tri[i][j]; 
    }
  }
  int max = dp[n-1][0];
  for(int j=1; j<n; j++){
    if(dp[n-1][j] > max) max = dp[n-1][j];
  }
  cout << max;
}