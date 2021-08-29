#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
  // ios::sync_with_stdio(0);
  // cin.tie(0);
  
  int x=1;
  printf("%d\n", (x<<0));
  printf("%d\n", (x<<1));
  printf("%d\n", (x<<2));
  char s[10]={};
  for(int i=0; i<3; i++){
    scanf("%s", s);
    // printf("%s\n", s);
    if(!strcmp(s,"hello")) printf("1\n");
    if(!strcmp(s,"hi")) printf("2\n");
    if(!strcmp(s,"hihi")) printf("3\n");
  }
  // cout << (x<<1);
}