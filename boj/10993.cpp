#include <stdio.h>
using namespace std;

char star[1030][2050]={};
int getwidth(int n){
  int t = 4, width=1;
  n--;
  while(n--){
    width += t;
    t *= 2;
  }
  return width;
}

int getheight(int n){
  int height=1;
  n--;
  while(n--){
    height = (height*2) + 1;
  }
  return height;
}

void triangle(int size, int x, int y){
  int width = getwidth(size);
  int height = getheight(size)-1;
  star[x][y+width/2] = '*';
  for(int i=1; i<height; i++){
    for(int j=0; j<(width/2)-i; j++) star[x+i][y+j] = ' ';
    star[x+i][y+(width/2)-i]='*';
    for(int j=width/2-i+1; j<width/2+i; j++) star[x+i][y+j] = ' ';
    star[x+i][y+(width/2)+i]='*';
  }
  for(int i=0; i<width; i++) star[x+height][y+i] = '*';
}

void reversed_triangle(int size, int x, int y){
  int width = getwidth(size);
  int height = getheight(size)-1;
  for(int i=0; i<width; i++) star[x][y+i] = '*';
  for(int i=1; i<height; i++){
    for(int j=0; j<i; j++) star[x+i][y+j] = ' ';
    star[x+i][y+i]='*';
    for(int j=i+1; j<width-1-i; j++) star[x+i][y+j] = ' ';
    star[x+i][y+width-1-i]='*';
  }
  star[x+height][y+width/2]='*';
}
void make(int size, int x, int y){
  int height;
  for(int i=size; i>0; i--){
    height = getheight(i);
    if(i%2==0){
      reversed_triangle(i,x,y);
      x += 1;
      y += ((height/2)+1);
    }
    else{
      triangle(i,x,y);
      x += (height/2);
      y += ((height/2)+1);
    }
  }
}
int main(){
  int N;
  scanf("%d", &N);
  int w = getwidth(N), h = getheight(N);
  for(int i=0; i<=h; i++){
    for(int j=0; j<=w; j++){
      star[i][j] = ' ';
    }
  }
  make(N, 0,0);
  if(N%2==1){
    for(int i=0; i<h; i++){
      for(int j=0; j<=w/2+i; j++){
        printf("%c", star[i][j]);
      }
      printf("\n");
    }
  }
  else{
    for(int i=0; i<h; i++){
      for(int j=0; j<=w-i; j++){
        printf("%c", star[i][j]);
      }
      printf("\n");
    }
  }
}