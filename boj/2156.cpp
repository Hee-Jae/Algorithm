#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int glass[10001]={}, n;
  int dp[10001]={};
  cin >> n;
  for(int i=0; i<n; i++) cin >> glass[i];
  dp[0] = glass[0];
  dp[1] = glass[0] + glass[1];
  dp[2] = max(glass[0]+glass[2], glass[1]+glass[2]);
  dp[2] = max(dp[2], dp[1]);

  for(int i=3; i<n; i++){
    dp[i] = max(dp[i-3]+glass[i-1]+glass[i], dp[i-2]+glass[i]);
    dp[i] = max(dp[i], dp[i-1]);
  }

  int ans = dp[n-1];
  cout << ans << "\n";
}