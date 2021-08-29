#include <iostream>
using namespace std;

// int dp[1002]={0,1,0,1,1};
int main(){
  ios::sync_with_stdio(0);
  
  long long N;
  cin >> N;
  // dp[16] = 1;
  // dp[64] = 1;
  // dp[256] = 1;
  // for(int i=5; i<=15; i++){
  //   if(!dp[i-1] || !dp[i-4]) dp[i] = 1;
  //   else dp[i] = 0;
  // }
  // for(int i=17; i<=255; i++){
  //   if(!dp[i-1] || !dp[i-4]) dp[i] = 1;
  //   else dp[i] = 0;
  // }
  // for(int i=257; i<=1000; i++){
  //   if(!dp[i-1] || !dp[i-4]) dp[i] = 1;
  //   else dp[i] = 0;
  // }
  // for(int i=1; i<=1000; i++){
  //   if(!dp[i]) cout << i << "  ";
  // }
  if(N%5 == 0 || N%5 == 2) cout << "CY";
  else cout << "SK";
}