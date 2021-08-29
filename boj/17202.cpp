#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define lli long long int
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  char A[10]={}, B[10]={}, ans[20]={};
  int tmp1, tmp2, tmp3;
  cin >> A >> B;
  for(int i=0; i<8; i++){
    ans[i*2] = A[i];
    ans[i*2+1] = B[i];
  }
  for(int i=15; i>=2; i--){
    for(int j=0; j<i; j++){
      tmp1 = (ans[j]-'0');
      tmp2 = (ans[j+1]-'0');
      tmp3 = (tmp1+tmp2)%10;
      ans[j] = (tmp3+'0');
    }
    // cout << ans << "\n";
  }

  cout << ans[0] << ans[1];
}
