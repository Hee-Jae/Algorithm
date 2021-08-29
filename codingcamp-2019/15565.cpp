#include <stdio.h>
int doll[1000000]={};

int main(){
    int N, K;
    scanf("%d %d", &N, &K);
    for(int i=0; i<N; i++) scanf("%d", &doll[i]);

    int S=0, E=0, min=1000000, lion=0;
    while(E<=N){
        if(lion == K){
            if(E-S < min) min = E-S;
            if(doll[S] == 1) lion--;
            S++;
        }
        else if(lion < K){
            if(E==N) break;
            if(doll[E] == 1) lion ++;
            E++;
        }
        else{
            if(doll[S] == 1) lion--;
            S++;
        }
    }
    if(min==1000000) printf("-1");
    else printf("%d", min);
}