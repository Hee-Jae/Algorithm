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

lli dp[1000010]={0,1,2,4};
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T,N;
  for(int i=4; i<=1000000; i++) dp[i] = (dp[i-1] + dp[i-2] + dp[i-3])%MOD;
  for(cin>>T; T; T--){
    cin >> N;
    cout << dp[N] << '\n';
  }
}
