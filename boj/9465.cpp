#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define lli long long int
using namespace std;

int stick[2][100002]={};
int dp[2][100002]={};
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T,n,mx=0,ans;
  for(cin >> T; T; T--){
    cin >> n;
    for(int i=1; i<=n; i++) cin >> stick[0][i];
    for(int i=1; i<=n; i++) cin >> stick[1][i];
    dp[0][1] = stick[0][1];
    dp[1][1] = stick[1][1];

    for(int i=2; i<=n; i++){
      dp[0][i] = max(dp[1][i-2],dp[1][i-1])+stick[0][i];
      dp[1][i] = max(dp[0][i-2],dp[0][i-1])+stick[1][i];
    }
    ans = max(dp[0][n], dp[1][n]);
    cout << ans << "\n";
  }
}
