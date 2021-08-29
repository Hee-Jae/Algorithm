#include <stdio.h>

int main(){
    int arr[10001]={};
    int N;
    long long M;
    scanf("%d %lld", &N, &M);
    for(int i=0; i<N; i++) scanf("%d", &arr[i]);

    int S=-1, E=-1;
    long long temp = 0, count=0;
    while(E<N){
        if(temp == M){
            count ++;
            S++;
            temp -= arr[S];
        }
        else if(temp > M){
            S++;
            temp -= arr[S];
        }
        else{
            E++;
            temp += arr[E];
        }
    }
    printf("%lld", count);
}