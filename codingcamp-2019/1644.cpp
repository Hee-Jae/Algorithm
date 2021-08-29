#include <stdio.h>
#include <cmath>
int isprime[4000001]={1,1};
int prime[1000001]={};
int main(){
    int N;
    scanf("%d", &N);
    for(int i=2; i<=2000; i++){
        for(int j=i+i; j<=4000000; j+=i) if(isprime[j]==0) isprime[j] = 1;
    }
    int j=0;
    for(int i=2; i<=4000000; i++) if(isprime[i]==0) prime[j++] = i;
    int E=-1, S=-1, count=0, temp=0;
    while(1){
        if(temp == N){
            count ++;
            S ++;
            temp -= prime[S];
        }
        else if(temp > N){
            S ++;
            temp -= prime[S];
        }
        else{
            E ++;
            temp += prime[E];
        }
        if(S>0 && prime[S] >= N) break;
    }
    printf("%d", count);
}