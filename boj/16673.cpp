#include <iostream>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int C, K, P;
  long long ans=0;
  cin >> C >> K >> P;
  for(int i=0; i<=C; i++){
    ans += (i*K + i*i*P);
  }
  cout << ans;
}