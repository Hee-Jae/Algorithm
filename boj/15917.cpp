#include <iostream>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int Q,a, flag;
  long long two=1;
  cin >> Q;
  for(int i=0; i<Q; i++){
    cin >> a;
    two = 1;
    flag = 0;
    for(int j=0; j<=31; j++){
      if(a == two){
        flag = 1;
        break;
      }
      two *= 2;
    }
    if(flag) cout << "1\n";
    else cout << "0\n";
  }
}