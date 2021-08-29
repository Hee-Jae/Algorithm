#include <stdio.h>
using namespace std;

int main(){
    int N;
    int len = 0;
    scanf("%d", &N);
    for(int i=1; i<=N; i++){
        if(i<10) len ++;
        else if(i<100) len +=2;
        else if(i<1000) len +=3;
        else if(i<10000) len +=4;
        else if(i<100000) len +=5;
        else if(i<1000000) len +=6;
        else if(i<10000000) len +=7;
        else if(i<100000000) len +=8;
        else if(i<1000000000) len +=9; 
    }
    printf("%d", len);
}