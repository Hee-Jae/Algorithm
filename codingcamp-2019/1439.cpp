#include <stdio.h>
char s[1000000]={};
int main(){
    scanf("%s", s);
    char prev=s[0];
    int c1=0, c2=1, flag=0;
    for(int i=0; s[i]!='\0'; i++){
        if(s[i] != prev && flag==0){
            c1++;
            flag = 1;
        }
        else if(s[i] != prev && flag==1){
            c2++;
            flag = 0;
        }
        prev = s[i];
    }
    if(c1 > c2) printf("%d", c2);
    else printf("%d", c1);
}