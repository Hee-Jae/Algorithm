#include <stdio.h>

int main(){
    int N;
    scanf("%d", &N);
    int S=0, E=0, M=0, count=0;
    while(S <= N){
        if(M == N){
            // printf("S:%d | E:%d\n", S, E);
            count++;
            E ++;
            M += E;
        }
        else if(M > N){
            S ++;
            M -= S;
        }
        else{
            E ++; 
            M += E;
        }
    }
    printf("%d", count);
}