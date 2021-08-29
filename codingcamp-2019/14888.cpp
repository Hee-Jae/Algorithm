#include <stdio.h>
using namespace std;

int realoper[12]={}, a[12]={}, n, max=-1000000000, min=1000000000;
void swap(int i, int j){
    int temp = realoper[i];
    realoper[i] = realoper[j];
    realoper[j] = temp;
}

void permutation(int s, int e){
    if(s==e){
        int res = a[0];
        for(int i=1; i<n; i++){
            if(realoper[i-1] == 0) res += a[i];
            else if(realoper[i-1] == 1) res -= a[i];
            else if(realoper[i-1] == 2) res *= a[i];
            else if(realoper[i-1] == 3) res /= a[i];
        }
        if(res > max) max = res;
        if(res < min) min = res;
    }
    else{
        for(int i=s; i<e; i++){
            swap(s,i);
            permutation(s+1,e);
            swap(s,i);
        }
    }
}
int main(){
    int oper[4]={};
    
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    for(int i=0; i<4; i++) scanf("%d", &oper[i]);
    for(int i=0, k=0; i<4; i++){
        for(int j=0; j<oper[i]; j++){
            realoper[k++] = i;
        }
    } //0:더하기 1:빼기 2:곱하기 3:나누기
    permutation(0,n-1);
    printf("%d\n%d",max,min);
}