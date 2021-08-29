#include <stdio.h>
int fibo[1000001]={0,1,2};
int main(){
    for(int i=3; i<=1000000; i++) fibo[i] = (fibo[i-1] + fibo[i-2])%15746;
    int n;
    scanf("%d", &n);
    printf("%d", fibo[n]);
}