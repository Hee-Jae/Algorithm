#include <stdio.h>

int main(){
    int fibo[51]={1,1};
    for(int i=2; i<=50; i++) fibo[i] = (fibo[i-1] + fibo[i-2] + 1)%1000000007;
    int n;
    scanf("%d", &n);
    printf("%d", fibo[n]);
}