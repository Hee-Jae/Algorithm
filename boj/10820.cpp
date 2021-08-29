#include <iostream>
#include <string>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  string str;
  int d,u,n,s;
  while(getline(cin,str)){
    // getline(cin,str);
    d = 0;
    u = 0;
    n = 0;
    s = 0;
    for(int i=0; str[i]!='\0'; i++){
      if('0' <= str[i] && str[i] <= '9') n++;
      else if('a' <= str[i] && str[i] <= 'z') d++;
      else if('A' <= str[i] && str[i] <= 'Z') u++;
      else if(str[i] == ' ') s++;
    }
    cout << d << " " << u << " " << n << " " << s << "\n";
  }
}