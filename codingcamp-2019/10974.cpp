#include <stdio.h>
int n, arr[9]={};

void right(int s, int e){
    int last = arr[e];
    for(int i=e; i>=s; i--) arr[i] = arr[i-1];
    arr[s] = last;
}

void left(int s, int e){
    int first = arr[s];
    for(int i=s; i<e; i++) arr[i] = arr[i+1];
    arr[e] = first;
}
void permutation(int s, int e){
    if(s==e){
        for(int i=0; i<n; i++) printf("%d ",arr[i]);
        printf("\n");
    }
    else{
        for(int i=s; i<e; i++){
            right(s,i);
            permutation(s+1,e);
            left(s,i);
        }
    }
}
int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++) arr[i] = i+1;
    permutation(0,n);
} // 왜 인지는 모르것다야...