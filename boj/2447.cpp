#include <stdio.h>
#include <string.h>
using namespace std;

char star[3000][3000]={};
void space(int size, int x, int y){
    for(int i=0; i<size ;i++){
        for(int j=0; j<size; j++) star[x+i][y+j] = ' ';
    }
}
void prt(int size, int x, int y){
    if(size==3){
        for(int i=0; i<3; i++) star[x][y+i] = '*';
        star[x+1][y]='*';
        star[x+1][y+1]=' ';
        star[x+1][y+2]='*';
        for(int i=0; i<3; i++) star[x+2][y+i] = '*';
    }
    else{
        for(int i=0; i<3; i++){
            prt(size/3, x+(size/3)*0, y+(size/3)*i);
        }
        prt(size/3, x+(size/3)*1, y+(size/3)*0);
        space(size, x+(size/3)*1, y+(size/3)*1);
        prt(size/3, x+(size/3)*1, y+(size/3)*2);
        
        for(int i=0; i<3; i++){
            prt(size/3, x+(size/3)*2, y+(size/3)*i);
        }
    }
}
int main(){
    int N;
    scanf("%d", &N);
    prt(N,0,0);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++) printf("%c", star[i][j]);
        printf("\n");
    }
}