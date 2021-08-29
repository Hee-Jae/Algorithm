#include <stdio.h>
#include <algorithm>
using namespace std;
int main(){
    int L,P,V, i=1;
    while(1){
        scanf("%d %d %d", &L, &P, &V);
        if(L==0 && P==0 && V==0) break;
        printf("Case %d: %d\n", i,(V/P)*L + min(V-(V/P)*P, L));
        i++;
    }
}