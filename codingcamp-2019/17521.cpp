#include <stdio.h>
using namespace std;

int main(){
    int n, flag=0, prev_flag=0;
    long long int w;
    int s[16]={}, dec[16]={}; //1이면 팔고, 2면 살거다 ㅇㅋ?
    scanf("%d %lld", &n, &w);
    for(int i=0; i<n; i++) scanf("%d", &s[i]);
    if(s[1] > s[0]){
        prev_flag = 1;
        dec[0] = 2;
    }
    else if(s[1] < s[0]){
        prev_flag = 2;
        dec[0] = 1;
    }
    for(int i=2; i<n; i++){
        if(s[i] > s[i-1]){
            flag=1;
            if(flag != prev_flag) dec[i-1] = 2;
            prev_flag = 1;
        }
        else if(s[i] < s[i-1]){
            flag=2;
            if(flag != prev_flag) dec[i-1] = 1;
            prev_flag = 2;
        }
        else continue;
    }

    long long int mycoin = 0;
    for(int i=0; i<n-1; i++){
        if(dec[i] == 2){
            mycoin += w/s[i];
            w -= mycoin*s[i];
        }
        else if(dec[i] == 1){
            w += mycoin*s[i];
            mycoin = 0;
        }
        // printf("%lld ", w);
    
    }
    // printf("\n");
    // for(int i=0; i<n; i++) printf("%d ", dec[i]);
    // printf("\n");

    if(mycoin > 0) w += mycoin*s[n-1];
    
    printf("%lld", w);
}