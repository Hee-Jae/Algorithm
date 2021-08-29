#include <iostream>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  char s[101]={};
  cin >> s;
  for(int i=0; s[i]!='\0'; i++){
    if(s[i]=='C' || s[i]=='A' || s[i]=='M' || s[i]=='B' || s[i]=='R' || s[i]=='I' || s[i]=='D' || s[i]=='G' || s[i]=='E'){
      continue;  
    } 
    else cout << s[i];
  }
}