#include <iostream>
using namespace std;
long long fact[4000001]={1,1};
long long inv[4000001]={};
long long power(long long x, long long y){
  long long ans = 1;
  while(y > 0){
    if(y%2==1){
      ans *= x;
      ans %= 1000000007;
    }
    x *= x;
    x %= 1000000007;
    y /= 2;
  }
  return ans;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  for(int i=2; i<=4000000; i++){
    fact[i] = (fact[i-1] * i)%1000000007;
  }
  inv[4000000] = power(fact[4000000], 1000000005)%1000000007;
  for(int i=3999999; i>=0; i--) inv[i] = (inv[i+1]*(i+1))%1000000007;
  int M, N, K;
  long long ans;
  for(cin >> M; M; M--){
    cin >> N >> K;
    if(K==0 || N==K) cout << "1\n";
    else{
      ans = (fact[N] * inv[N-K])%1000000007;
      ans = (ans * inv[K]) % 1000000007;
      cout << ans << "\n";
    }
  }
}