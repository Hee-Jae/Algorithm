#include <iostream>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, temp = 0, palin=0;
  while(1){
    cin >> n;
    if(n == 0) break;
    temp = n;
    palin = 0;
    while(temp){
      palin = palin*10 + temp%10;
      temp /= 10;
    }
    if(palin == n) cout << "yes\n";
    else cout << "no\n";
  }
}