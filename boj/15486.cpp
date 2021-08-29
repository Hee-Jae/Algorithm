#include <iostream>
using namespace std;

int N, maxpay=0;
int dp[1500010]={}, prev[1500010]={};
int T[1500010]={}, P[1500010]={};

// void getmax(int i, int pay){
//   if(maxpay < pay) maxpay = pay;
//   if(i >= N) return;
//   if(i+T[i] <= N) getmax(i+T[i], pay+P[i]);
//   if(i+1 < N) getmax(i+1, pay);
// }
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N;
  for(int i=1; i<=N; i++){
    cin >> T[i] >> P[i];
    if(i+T[i] > N+1) P[i] = 0;
    
  }
  int next;
  for(int i=1; i<=N; i++){
    next = i+T[i];
    if(next <= N){
      if(dp[next] < P[i]) dp[next] = P[i];
    }
    dp[i] += dp[i-1];
  }
  for(int i=1; i<=N; i++) P[i] += dp[i];
  for(int i=1; i<=N; i++) if(P[i] > maxpay) maxpay = P[i];
  for(int i=1; i<=N; i++) cout << dp[i] << " ";
  cout << "\n";
  cout << maxpay;
}