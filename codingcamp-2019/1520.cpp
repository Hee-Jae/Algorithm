#include <stdio.h>

using namespace std;
int M,N, cnt=0;
int map[501][501]={};
int check[501][501]={};
int dir[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};

void ptr(){
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            printf("%d ", check[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
int dfs(int x, int y){
    cnt ++;
    int xx, yy;
    if(x == M-1 && y == N-1) return 1;
    if(check[x][y] != -1) return check[x][y];
    else{
        check[x][y] = 0;
        for(int i=0; i<4; i++){
            xx = x + dir[i][0];
            yy = y + dir[i][1];
            if(0 <= xx && xx < M && 0 <= yy && yy < N){
                if(map[xx][yy] < map[x][y]){
                    check[x][y] += dfs(xx,yy);
                    // cnt ++;
                    // ptr();
                }
            }
        }
    }
    return check[x][y];
}
int main(){
    scanf("%d %d", &M, &N);
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            scanf("%d", &map[i][j]);
            check[i][j] = -1;
        }
    }
    
    printf("%d\n", dfs(0,0));
    printf("cnt : %d\n", cnt);
}