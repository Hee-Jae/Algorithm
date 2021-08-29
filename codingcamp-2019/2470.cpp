#include <stdio.h>
#include <algorithm>
#include <cmath>
using namespace std;

int arr[100001]={};
int main(){
    int N;
    scanf("%d", &N);
    for(int i=0; i<N; i++) scanf("%d", &arr[i]);
    sort(arr, arr+N);
    int s=0, e=N-1, temp, min=2000000000;
    int left=arr[0], right=arr[N-1];
    while(s!=e){
        temp = arr[s] + arr[e];
        if(abs(temp) < min){
            min = abs(temp);
            left = arr[s];
            right = arr[e];
        }
        if(temp < 0) s++;
        else if(temp > 0) e--;
        else{
            left = arr[s];
            right = arr[e];
            break;
        }
    }
    printf("%d %d", left, right);
}