#include <stdio.h>
#include <algorithm>
using namespace std;
int dp[1000001]={}; //i번째 자리까지 오는데 걸린 시간이야
int main(){
    int N,a,b;
    scanf("%d %d %d", &N, &a, &b);
    for(int i=1; i<=N; i++) dp[i] = 987654321;
    for(int i=0; i<N; i++){
        dp[i+1] = min(dp[i]+1, dp[i+1]);
        if(i+a+1 <= N) dp[i+a+1] = min(dp[i]+1, dp[i+a+1]);
        if(i+b+1 <= N) dp[i+b+1] = min(dp[i]+1, dp[i+b+1]);
    }
    printf("%d", dp[N]);
}