#include <iostream>
using namespace std;
long long fact[4000001]={1,1};
long long inv[4000001]={};
long long power(long long x, long long y){
  long long ans = 1;
  while(y > 0){
    if(y%2==1){
      ans *= x;
      ans %= 16;
    }
    x *= x;
    x %= 16;
    y /= 2;
  }
  return ans;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  for(int i=2; i<=4000000; i++){
    fact[i] = (fact[i-1] * i)%16;
  }
  inv[4000000] = power(fact[4000000], 14)%16;
  for(int i=3999999; i>=0; i--) inv[i] = (inv[i+1]*(i+1))%16;
  int N, K;
  long long ans;
  cin >> N >> K;
  if(K==0 || N==K) cout << "1\n";
  else{
    ans = (fact[N] * inv[N-K])%16;
    ans = (ans * inv[K]) % 16;
    cout << ans << "\n";
  }
}