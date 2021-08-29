#include <iostream>
#include <string>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N, alpa[27]={};
  cin >> N;
  for(int i=0; i<N; i++){
    string s;
    cin >> s;
    alpa[s[0]-'a'] ++;
  }

  int flag=1;
  for(int i=0; i<26; i++){
    if(alpa[i] >= 5){
      cout << (char)('a'+i);
      flag = 0;
    }
  }
  if(flag) cout << "PREDAJA";
}