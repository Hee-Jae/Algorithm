#include <iostream>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  long long N, ans=0;
  cin >> N;
  for(int i=1; i<N; i++) ans+=(N*i + i);
  cout << ans;
}