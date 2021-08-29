#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define lli long long int
#define MOD 1000000009
using namespace std;
lli T, N, dp[100010][5]={};
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  dp[1][1]=1;
  dp[2][2]=1;
  for(int i=1; i<=3; i++) dp[3][i]=1;
  for(int i=4; i<=100000; i++){
    dp[i][1] = (dp[i-1][2] + dp[i-1][3])%MOD;
    dp[i][2] = (dp[i-2][1] + dp[i-2][3])%MOD;
    dp[i][3] = (dp[i-3][2] + dp[i-3][1])%MOD;
  }
  lli ans;
  for(cin>>T; T; T--){
    cin >> N;
    ans = (dp[N][1] + dp[N][2] + dp[N][3])%MOD;
    cout << ans << "\n";
  }
}
