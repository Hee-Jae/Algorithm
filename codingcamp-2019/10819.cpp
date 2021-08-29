#include <stdio.h>
#include <cmath>
using namespace std;

int arr[9]={};
int N, max = 0;

void swap(int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void permu(int s, int e){
    if(s == e){
        int value=0;
        for(int i=1; i<N; i++){
            value += abs(arr[i]-arr[i-1]);
        }
        if(value > max) max = value;
    }

    else{
        for(int i=s; i<e; i++){
            swap(s,i);
            permu(s+1, e);
            swap(s,i);
        }
    }
}
int main(){    
    scanf("%d", &N);
    for(int i=0; i<N; i++) scanf("%d", &arr[i]);
    permu(0,N);
    printf("%d", max);
}