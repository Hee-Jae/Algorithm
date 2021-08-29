#include <stdio.h>
#include <string.h>
using namespace std;

int main(){
  int M, state=0, x;
  char s[10]={};
  scanf("%d", &M);
  while(M--){
    scanf("%s", s);
    if(!strcmp(s,"add")){
      scanf("%d", &x);
      state |= (1<<x);
    }
    else if(!strcmp(s, "remove")){
      scanf("%d", &x);
      if(state&(1<<x)) state -= (1<<x);
    }
    else if(!strcmp(s, "toggle")){
      scanf("%d", &x);
      if(state&(1<<x)) state -= (1<<x);
      else state |= (1<<x);
    }
    else if(!strcmp(s, "check")){
      scanf("%d", &x);
      if(state&(1<<x)) printf("1\n");
      else printf("0\n");
    }
    else if(!strcmp(s, "all")){
      state = (1<<21)-1;
    }
    else if(!strcmp(s, "empty")){
      state = 0;
    }
  }
}