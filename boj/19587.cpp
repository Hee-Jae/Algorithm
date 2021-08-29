#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define lli long long int
#define MOD 1000000007
#define matrix vector<vector<lli> >
using namespace std;

// double fastpow(double a, lli n){
//   double res = 1;
//   while(n){
//     if(n%2==0){
//       a=a*a;
//       n/=2;
//       if(a>=MOD) a -= (a/MOD)*MOD;
//     }
//     else{
//       res=res*a;
//       n--;
//       if(res>=MOD) res -= (res/MOD)*MOD;
//     }
//   }
//   return res;
// }

matrix multiply(matrix a, matrix b){
  matrix ans(2);
  for(int i=0; i<2; i++){
    for(int j=0; j<2; j++){
      ans[i].pb(0);
      for(int k=0; k<2; k++){
        ans[i][j] += (a[i][k] * b[k][j])%MOD;
        ans[i][j] %= MOD;
      }
    }
  }
  return ans;
}

matrix fast(matrix a, lli n){
  if(n==1) return a;
  if(n%2==0){
    matrix t = fast(a,n/2);
    return multiply(t,t);
  }
  else return multiply(fast(a,n-1),a);
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  lli N;
  // double left, right;
  // double sqrt2 = sqrt(2);
  cin >> N;
  if(N==1) cout << 3;
  else if(N==2) cout << 7;
  else{
    matrix a(2);
    a[0].pb(2);
    a[0].pb(1);
    a[1].pb(1);
    a[1].pb(0);
    N-=2;
    a = fast(a,N);
    lli ans;
    ans = ((a[0][0]*7)%MOD + (a[0][1]*3)%MOD)%MOD;
    cout << ans;
    // left = fastpow(1+sqrt2,N+1) * (4+3*sqrt2);
    // right = fastpow(1-sqrt2,N+1) * (4-3*sqrt2);
    // if(left>=MOD) left -= (left/MOD)*MOD;
    // if(right>=MOD) right -= (right/MOD)*MOD;
    // ans = (left-right)/(2*sqrt2);
    // if(ans%2==0) cout << (ans+1)%MOD;
    // else cout << ans%MOD;
  }
}
