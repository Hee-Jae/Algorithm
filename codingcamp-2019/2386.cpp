#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
int main(){
    string str;
    char key;
    int count=0;
    while(1){
        count = 0;
        scanf("%c", &key);
        if(key == '#') break;
        getline(cin, str);
        
        for(int i=0; str[i] != '\0'; i++){
            if(str[i] == key) count++;
            else if(str[i] <= 'Z' && str[i] - 'A' == key-'a') count++;
        }
        printf("%c %d\n", key, count);
    }
}