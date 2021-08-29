#include <stdio.h>
using namespace std;
int weight[50001]={};
int sw[50001]={};
int main(){
    for(int i=0, k=3; i<=50000; i++, k+=2) weight[i] = k;
    for(int i=0; i<=50000; i++) sw[i] = i;
    // for(int i=0; i<100; i++) printf("%d ", sw[i]);
    int G;
    scanf("%d", &G);

    int S=-1, E=-1, temp=0, flag=0;
    while(1){
        if(temp == G){
            flag = 1;
            // printf("S:%d | E:%d\n", S, E);
            S++;
            temp -= weight[S];
            printf("%d\n", sw[E+2]);
        }
        else if(temp > G){
            S++;
            temp -= weight[S];
        }
        else{
            E++;
            temp += weight[E];
        }
        if(S>=0 && weight[S]>=G) break;
    }
    if(flag==0) printf("-1");
}