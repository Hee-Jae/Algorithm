#include <iostream>
#include <algorithm>
using namespace std;
int arr[102]={}, dp[100002]={};
int N, K;
int maxdp(int coin){
  int value=0, min=99999;
  for(int i=coin-1; i>(coin-1)/2; i--){
    // if(coin == 16) cout << i << " : " << dp[i] << " | " << coin-i << " : " <<dp[coin-i] << "\n";
    if(dp[i] != 0 && dp[coin-i] != 0) value = dp[i] + dp[coin-i];
    if(min > value && value != 0) min = value;
    // if(coin == 16) cout << "min : " << min << "\n";
  }
  if(min==99999) return 0;
  else return min;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> K;
  for(int i=1; i<=N; i++) cin >> arr[i];
  sort(arr, arr+N+1);
  for(int i=1; i<=N; i++) dp[arr[i]] = 1;
  for(int i=1; i<=K; i++)
    if(dp[i]==0) dp[i] = maxdp(i);
  // for(int i=1; i<=96; i++) cout << i << ":" <<dp[i] << "\n"; 
  if(dp[K] == 0) cout << "-1";
  else cout << dp[K];
}