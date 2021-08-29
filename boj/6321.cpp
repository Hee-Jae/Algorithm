#include <iostream>
#include <string>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for(int i=1; i<=n; i++){
    string s;
    cin >> s;
    cout << "String #" << i << "\n";
    for(int i=0; s[i]!='\0'; i++){
      if(s[i] == 'Z') cout << 'A';
      else cout << (char)(s[i]+1);
    }
    cout << "\n\n";
  }
}