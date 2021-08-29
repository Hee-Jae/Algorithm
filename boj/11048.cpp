#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define lli long long int
using namespace std;

int N,M, miro[1010][1010]={};
int dp[1010][1010]={};
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for(int i=0; i<N; i++)
    for(int j=0; j<M; j++) cin >> miro[i][j];
  
  dp[0][0] = miro[0][0];
  for(int i=1; i<M; i++) dp[0][i] = dp[0][i-1] + miro[0][i];
  for(int i=1; i<N; i++) dp[i][0] = dp[i-1][0] + miro[i][0];

  for(int i=1; i<N; i++){
    for(int j=1; j<M; j++){
      dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]);
      dp[i][j] = max(dp[i][j], dp[i][j-1]);
      dp[i][j] += miro[i][j];
    }
  }
  cout << dp[N-1][M-1] << "\n";
}
