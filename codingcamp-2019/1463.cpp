#include <stdio.h>
using namespace std;
int x[1000001]={0,0,1,1};

int main(){
    for(int i=4; i<=1000000; i++){ x[i] = 987654321; }
    for(int i=4; i<=1000000; i++){
        int temp1=i, temp2=i, temp3=i;
        if(temp1%3==0) temp1/=3;
        if(temp2%2==0) temp2/=2;
        temp3 --;
        //if(i==10) printf("%d %d %d\n", x[temp1], x[temp2], x[temp3]);
        if(x[temp1] >= x[temp3] && x[temp2] >= x[temp3]) x[i] = 1+x[temp3];
        else if(x[temp1] >= x[temp2] && x[temp3] >= x[temp2]) x[i] = 1+x[temp2];
        else if(x[temp3] >= x[temp1] && x[temp2] >= x[temp1]) x[i] = 1+x[temp1];
    }
    int n;
    scanf("%d", &n);
    printf("%d", x[n]);
}