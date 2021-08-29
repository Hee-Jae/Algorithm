#include <iostream>
using namespace std;

long long expo(int n){
  long long res = 1;
  while(n){
    res = (res*31)%1234567891;
    n --;
  }
  return res;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int L;
  long long hash = 0;
  char str[51]={};
  cin >> L;
  cin >> str;
  for(int i=0; i<L; i++){
    hash = (hash + ((str[i]-'a'+1)*expo(i))%1234567891) % 1234567891;
  }
  cout << hash;
}