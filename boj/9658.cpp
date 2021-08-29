#include <iostream>
using namespace std;

int dp[1002]={0,0,1,0,1};
int main(){
  ios::sync_with_stdio(0);
  for(int i=5; i<=1000; i++){
    if(!dp[i-1] || !dp[i-3] || !dp[i-4]) dp[i] = 1;
    else dp[i] = 0;
  }
  int N;
  cin >> N;
  if(dp[N]) cout << "SK\n";
  else cout << "CY\n";

}