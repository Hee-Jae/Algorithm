#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define lli long long int
using namespace std;

int bitcnt(int n){
  int cnt=0;
  while(n){
    if(n&1) cnt++;
    n >>= 1;
  }
  return cnt;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N,K,ans=0;
  cin >> N >> K;

  while(bitcnt(N) > K){
    N++;
    ans++;
  }
  cout << ans;
}
