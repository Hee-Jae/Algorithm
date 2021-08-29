#include <stdio.h>
#include <cmath>
using namespace std;

int arr[100001]={};
int main(){
    int N;
    scanf("%d", &N);
    for(int i=0; i<N; i++) scanf("%d", &arr[i]);
    int s=0, e=N-1, temp, min=2000000000;
    while(s!=e){
        temp = arr[s] + arr[e];
        if(abs(temp) < abs(min)) min = temp;
        if(temp < 0) s++;
        else if(temp > 0) e--;
        else{
            min = temp;
            break;
        }
    }
    printf("%d", min);
}