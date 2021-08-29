#include <stdio.h>
using namespace std;

int main(){
    int n, key=3;
    int baesu[1001]={};
    for(int i=0; i<=1000; i++){
        baesu[i] = key;
        key += 3;
        if(key==3003) break;
    }

    scanf("%d", &n);
    int count = 0;
    for(int i=0; i<1000; i++){
        if(baesu[i] >= n) break;
        for(int j=0; j<1000; j++){
            if(baesu[j] >= n) break;
            if(n - baesu[i] - baesu[j] >= 3) count++;
        }
    }
    printf("%d", count);
}