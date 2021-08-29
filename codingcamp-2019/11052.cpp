#include <iostream>
#include <algorithm>
using namespace std;
int arr[1001]={}, dp[1001]={};

int maxdp(int n){
  int value=0, max=0;
  for(int i=n-1; i>=1; i--){
    value = 0;
    value += dp[i] * (n/i);
    value += dp[n%i];
    if(max < value) max = value;
  }
  return max;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin >> N;
  for(int i=1; i<=N; i++) cin >> arr[i];
  dp[1] = arr[1];
  for(int i=2; i<=N; i++) dp[i] = max(maxdp(i),arr[i]);
  // for(int i=1; i<=N; i++) cout << dp[i] << " "; 
  cout << dp[N];
}