#include <stdio.h>
#include <algorithm>
using namespace std;
int main(){
    int house[1000][3]={};
    int dp[1000][3]={};
    
    int N;
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        for(int j=0; j<3; j++) scanf("%d", &house[i][j]);
    }
    dp[0][0] = house[0][0];
    dp[0][1] = house[0][1];
    dp[0][2] = house[0][2];

    for(int i=1; i<N; i++){
        for(int j=0; j<3; j++){
            if(j==0) dp[i][j] = min(dp[i-1][1]+house[i][j], dp[i-1][2]+house[i][j]);
            else if(j==1) dp[i][j] = min(dp[i-1][0]+house[i][j], dp[i-1][2]+house[i][j]);
            else if(j==2) dp[i][j] = min(dp[i-1][1]+house[i][j], dp[i-1][0]+house[i][j]);
        }
    }
    int minimum = min(dp[N-1][0], dp[N-1][1]);
    minimum = min(minimum, dp[N-1][2]);
    printf("%d", minimum);
}