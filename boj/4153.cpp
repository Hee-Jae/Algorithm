#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int a,b,c;
  while(1){
    cin >> a >> b >> c;
    if(a==0 && b==0 && c==0) break;
    if((a*a == (b*b + c*c)) || (b*b == (a*a + c*c)) || (c*c == (a*a + b*b))) cout << "right\n";
    else cout << "wrong\n";
  }
}
