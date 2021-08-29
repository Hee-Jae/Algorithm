#include <stdio.h>
using namespace std;

int main(){
    int arr[1000]={};
    int n;
    int num, s, b;
    for(int i=111; i<=999; i++){
        if(i%10 != 0 && (i/10)%10 != 0) arr[i] = i;
        if(i%10 == (i/10)%10) arr[i] = 0;
        if(i%10 == (i/100)%10) arr[i] = 0;
        if((i/10)%10 == (i/100)%10) arr[i] = 0;
    }
    scanf("%d", &n);
    int strike=0, ball=0;
    int a1,b1,c1;
    int aa, bb, cc;
    for(int i=0; i<n; i++){
        scanf("%d %d %d", &num, &s, &b);
        a1 = num%10;
        b1 = (num/10)%10;
        c1 = (num/100)%10;
        for(int j=111; j<=999; j++){
            if(arr[j] == 0) continue;     
            strike=0;
            ball=0;
            // printf("[%d%d%d]\n",a,b,c);
            aa = arr[j]%10;
            bb = (arr[j]/10)%10;
            cc = (arr[j]/100)%10;
            if(a1 == aa) strike ++;
            else{
                if(a1 == bb) ball ++;
                if(a1 == cc) ball ++;
            }
            if(b1 == bb) strike ++;
            else{
                if(b1 == aa) ball ++;
                if(b1 == cc) ball ++;
            }
            if(c1 == cc) strike ++;
            else{
                if(c1 == aa) ball ++;
                if(c1 == bb) ball ++;
            }
            

            if(strike != s || ball != b) arr[j] = 0;
        }
        // for(int j=111; j<=999; j++) printf("%d ", arr[j]);
    }
    int count=0;
    for(int i=111; i<=999; i++){
        if(arr[i] != 0) count ++;
    }
    printf("%d", count);
}