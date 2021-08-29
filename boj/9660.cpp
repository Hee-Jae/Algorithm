#include <iostream>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  
  long long N;
  cin >> N;
  if(N%7 == 0 || N%7 == 2) cout << "CY";
  else cout << "SK";
}