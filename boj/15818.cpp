#include <iostream>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  long long m, ans=1, num;
  cin >> n >> m;
  for(int i=0; i<n; i++){
    cin >> num;
    ans = (ans*(num%m))%m;
  }
  cout << ans;
}