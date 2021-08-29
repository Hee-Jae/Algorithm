#include <stdio.h>

int num[100001]={};
int main(){
    int N,M;
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++) scanf("%d", &num[i]);

    int E=0, S=0, min=987654, temp=0;
    while(1){
        if(temp >= M){
            if(E-S < min) min=E-S;
            temp -= num[S];
            S++;
        }
        else{
            if(E>=N) break;
            temp += num[E];
            E++;
        }
    }
    if(min==987654) printf("0");
    else printf("%d",min);
}