#include <stdio.h>
using namespace std;

char candy[51][51]={};
int maxlen(int n){
    int len=1, maxlen=0;
    char prev;
    for(int i=0; i<n; i++){
        prev = candy[i][0];
        len=1;
        for(int j=1; j<n; j++){
            // printf("[%d][%d] : %c || prev : %c\n", i,j,candy[i][j], prev);
            if(candy[i][j] != prev){
                // printf("[%d][%d] : %c || prev : %c\n", i,j,candy[i][j], prev);
                if(maxlen < len){
                    maxlen = len;
                    // printf("row!\n");
                    // printf("[%d][%d] : %c\n", i,j,prev);
                }
                len = 1;
            }
            else len ++;
            prev = candy[i][j];
        }
        if(maxlen < len) maxlen = len;
    }
    
    // printf("temp maxvlue : %d\n", maxlen);
    len = 1;
    for(int i=0; i<n; i++){
        prev = candy[0][i];
        len = 1;
        for(int j=1; j<n; j++){
            if(candy[j][i] != prev){
                if(maxlen < len){
                    maxlen = len;
                    // printf("row!\n");
                    // printf("[%d][%d] : %c\n", i,j,prev);
                }
                len = 1;
            }
            else len ++;
            prev = candy[j][i];
        }
        if(maxlen < len) maxlen = len;
    }
    
    return maxlen;
}

int main(){
    int N;
    int dir[4][2] = {{0,1}, {1,0}, {-1,0}, {0,-1}};
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%s", candy[i]);
    }
    
    int max=0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            for(int k=0; k<4; k++){
                int ii = i + dir[k][0];
                int jj = j + dir[k][1];
                if(ii >= 0 && ii < N && jj >= 0 && jj < N){
                    if(candy[i][j] != candy[ii][jj]){
                        char temp = candy[i][j];
                        candy[i][j] = candy[ii][jj];
                        candy[ii][jj] = temp;
                        if(max < maxlen(N)) max = maxlen(N);
                        temp = candy[i][j];
                        candy[i][j] = candy[ii][jj];
                        candy[ii][jj] = temp;
                    }
                }
            }
        }
    }
    printf("%d", max);
}