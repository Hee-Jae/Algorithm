#include <stdio.h>
int flag = 0;
int main(){
    int b,n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        char a[51];
        int counta = 0;
        int realcounta = 0;
        int realcountb = 0;
        int countb = 0;
        scanf("%s", a);
        for(int j=0; a[j] != '\0'; j++){
            if(a[j] == '('){
                flag = 1;
                counta++;
                realcounta++;
            } if (counta == countb){
                flag = 0;
            } if(a[j] == ')' && flag == 1){
                countb++;
                realcountb++;
            } if(a[j] == ')' && flag == 0){
                realcountb++;
            }
        }
        if(counta == countb && realcounta == realcountb){
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}