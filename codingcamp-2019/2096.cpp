#include <stdio.h>
#include <algorithm>
using namespace std;
int dp[100000][3]={};
int map[100000][3]={};
int main(){
    int N;
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        for(int j=0; j<3; j++) scanf("%d", &map[i][j]);
    }

    dp[0][0] = map[0][0];
    dp[0][1] = map[0][1];
    dp[0][2] = map[0][2];

    for(int i=1; i<N; i++){
        for(int j=0; j<3; j++){
            if(j==0) dp[i][j] = map[i][j] + max(dp[i-1][0], dp[i-1][1]);
            else if(j==1) dp[i][j] = map[i][j] + max(max(dp[i-1][0], dp[i-1][1]),dp[i-1][2]);
            else if(j==2) dp[i][j] = map[i][j] + max(dp[i-1][1], dp[i-1][2]);
        }
    }
    int maxv = max(max(dp[N-1][0], dp[N-1][1]),dp[N-1][2]);

    for(int i=1; i<N; i++){
        for(int j=0; j<3; j++){
            if(j==0) dp[i][j] = map[i][j] + min(dp[i-1][0], dp[i-1][1]);
            else if(j==1) dp[i][j] = map[i][j] + min(min(dp[i-1][0], dp[i-1][1]),dp[i-1][2]);
            else if(j==2) dp[i][j] = map[i][j] + min(dp[i-1][1], dp[i-1][2]);
        }
    }
    int minv = min(min(dp[N-1][0], dp[N-1][1]),dp[N-1][2]);
    printf("%d %d", maxv, minv);
}