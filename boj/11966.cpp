#include <iostream>
using namespace std;

int main(){
  long long N, flag=0, temp=1;
  cin >> N;
  for(int i=0; i<=30; i++){
    if(temp == N){
      flag = 1;
      break;
    }
    temp *= 2;
  }
  if(flag) cout << "1";
  else cout << "0";
}