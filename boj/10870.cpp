#include <stdio.h>

int main(){
    long long fibo[91]={0,1};
    int n;
    scanf("%d", &n);
    for(int i=2; i<=90; i++) fibo[i] = fibo[i-1] + fibo[i-2];
    printf("%lld", fibo[n]);
}