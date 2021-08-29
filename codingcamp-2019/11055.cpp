#include <iostream>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int A[1001]={}, dp[1001]={};
  int N, temp;
  cin >> N;
  for(int i=0; i<N; i++) cin >> A[i];
  for(int i=0; i<N; i++) dp[i] = A[i];
  for(int i=0; i<N; i++){
    temp = A[i];
    for(int j=i-1; j>=0; j--){
      if(A[i] > A[j]){
        if(A[i] + dp[j] > temp) temp = A[i] + dp[j];
      }
    }
    dp[i] = temp;
  }
  int max=0;
  for(int i=0; i<N; i++){
    // cout << i << " : " << dp[i] << "\n";
    if(max < dp[i]) max = dp[i];
  }
  cout << max;
}