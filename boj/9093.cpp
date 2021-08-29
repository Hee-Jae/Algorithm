// #include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main(){
  int T;
  cin >> T;
  for(int i=0; i<=T; i++){
    string s;
    getline(cin,s);
    if(i==0) continue;
    int prev=0, space=0, len=s.length();
    for(int i=0; i<len; i++){
      if(s[i] == ' '){
        space = i;
        for(int j=space-1; j>=prev; j--) cout << s[j];
        cout << ' ';
        prev = space+1;
      }
      if(i == len-1){
        for(int j=len-1; j>=prev; j--) cout << s[j];
      }
    }
    cout << "\n";
  }
}