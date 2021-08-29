#include <stdio.h>

int main(){
    int money;
    scanf("%d", &money);
    int taro = 1000-money, count=0;
    count += taro/500;
    taro %= 500;
    count += taro/100;
    taro %= 100;
    count += taro/50;
    taro %= 50;
    count += taro/10;
    taro %= 10;
    count += taro/5;
    taro %= 5;
    count += taro;

    printf("%d", count);
}