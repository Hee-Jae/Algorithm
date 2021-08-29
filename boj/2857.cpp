#include <iostream>
#include <string>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int flag=1;
  for(int i=1; i<=5; i++){
    string s;
    cin >> s;
    for(int j=0; j<s.length()-2; j++){
      if(s[j] == 'F' && s[j+1] == 'B' && s[j+2] == 'I'){
        cout << i << " ";
        flag = 0;
        break;
      }
    }
  }
  if(flag) cout << "HE GOT AWAY!";
}