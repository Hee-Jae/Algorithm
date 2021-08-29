#include <stdio.h>
#include <algorithm>
#include <functional>
using namespace std;
int num[100001]={};
int main(){
    int N,M;
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++) scanf("%d", &num[i]);
    sort(num, num+N, greater<int>());
    int S=0, E=0, temp=0, min=2000000001;
    while(1){
        if(E>=N){
            E=N-1;
            S++;
            if(S>=N) break;
        }
        if(num[S]-num[E] >= M){
            if(num[S]-num[E] < min) min = num[S]-num[E];
            S++;
            if(S>=N) break;
        }
        else E++;
    }
    printf("%d", min);
}