#include <stdio.h>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
    int N,M;
    int book[10001]={};
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++) scanf("%d", &book[i]);
    sort(book, book+N);
    
    int minus[10001]={}, plus[10001]={};
    int midx=0, pidx=0;
    for(int i=0; i<N; i++){
        if(book[i] < 0) minus[midx++] = book[i];
        else if(book[i] > 0) plus[pidx++] = book[i];
    }

    int ans=0;
    if(abs(minus[0]) > plus[pidx-1]){
        if(M >= pidx){
            // printf("Hello~\n");
            ans = plus[pidx-1]*2;
            // printf("%d\n", ans);
        }
        else{
            if(pidx%M != 0){
                ans += plus[pidx%M-1]*2;
                for(int i=pidx%M-1+M; i<pidx; i+=M) ans += plus[i]*2;
            }
            else{
                for(int i=M-1; i<pidx; i+=M) ans+= plus[i]*2;
            }
        }

        if(M >= midx){
            ans += abs(minus[0]);
            // printf("Hi~\n");
            // printf("%d\n", ans);
        }
        else{
            if(midx%M != 0){
                ans += abs(minus[midx-midx%M])*2;
                for(int i=midx-midx%M-M; i>0; i-=M) ans+= abs(minus[i])*2;
                ans += abs(minus[0]);
            }
            else{
                for(int i=midx-M; i>0; i-=M) ans+= abs(minus[i])*2;
                ans += abs(minus[0]);
            }
        }   
    }
    else{
        if(M >= pidx) ans = plus[pidx-1];
        else{
            if(pidx%M != 0){
                ans += plus[pidx%M-1]*2;
                for(int i=pidx%M-1+M; i<pidx-1; i+=M) ans += plus[i]*2;
                ans += plus[pidx-1];
            }
            else{
                for(int i=M-1; i<pidx-1; i+=M) ans+= plus[i]*2;
                ans += plus[pidx-1];
            }
        }
        
        if(M >= midx) ans += abs(minus[0])*2;
        else{
            if(midx%M != 0){
                ans += abs(minus[midx-midx%M])*2;
                for(int i=midx-midx%M-M; i>=0; i-=M) ans+= abs(minus[i])*2;
            }
            else{
                for(int i=midx-M; i>=0; i-=M) ans+= abs(minus[i])*2;
            }
        }
    }

    // for(int i=0; i<pidx; i++) printf("%d ", plus[i]);
    // printf("\n");
    // if(N<=M){
    //     if(abs(minus[0]) > plus[pidx-1]) printf("%d", plus[pidx-1]*2 + abs(minus[0]));
    //     else printf("%d", plus[pidx-1] + abs(minus[0])*2);
    // }
    printf("%d", ans);
}