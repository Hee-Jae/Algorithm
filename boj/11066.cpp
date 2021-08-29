#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define lli long long int
using namespace std;
 
int dp[510][510]={};
int cost[510]={};
int sum[510]={};
int t, k, y;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(cin >> t; t; t--){
      cin >> k;
      for (int i = 1; i <= k; i++) {
          cin >> cost[i];
          sum[i] = sum[i - 1] + cost[i];
      }

      for (int i = 1; i < k; i++) {
          for (int j = 1; j+i <= k; j++) {
              int y = j + i;
              dp[j][y] = 987654321;

              for (int m = j; m < y; m++)
                  dp[j][y] = min(dp[j][y], dp[j][m] + dp[m + 1][y] + sum[y] - sum[j - 1]);
          }
      }
      printf("%d\n", dp[1][k]);
    }
    return 0;
}
