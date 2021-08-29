#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define lli long long int
using namespace std;
int a[60]={};
bool dp[2510][2510]={};
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, sum=0;
  cin >> N;
  for(int i=0; i<N; i++){
    cin >> a[i];
    sum += a[i];
  }
  dp[0][0] = true;
  for(int i=0; i<N; i++){
    for(int j=sum; j>=0; j--){
      for(int k=sum; k>=0; k--){
        if(j-a[i] >= 0) dp[j][k] |= dp[j-a[i]][k];
        if(k-a[i] >= 0) dp[j][k] |= dp[j][k-a[i]];
      }
    }
  }
  int ans = 0, kw;
  for(int i=0; i<=sum; i++){
    for(int j=0; j<=i; j++){
      kw = sum-i-j;
      if(dp[i][j] && j >= kw){
        if(ans < kw) ans = kw;
      }
    }
  }
  cout << ans;
}
