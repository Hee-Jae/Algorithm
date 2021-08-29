#include <iostream>
#include <vector>
#define pb push_back
#define ll long long
#define matrix vector<vector<ll > >
#define mod 1000000007
using namespace std;

matrix gop(matrix a, matrix b){
  matrix ans(2);
  for(int i=0; i<2; i++){
    for(int j=0; j<2; j++){
      ans[i].pb(0);
      for(int k=0; k<2; k++){
        ans[i][j] += (a[i][k]*b[k][j])%mod;
        ans[i][j] %= mod;
      }
    }
  }
  return ans;
}

matrix fast(matrix a, ll b){
  if(b==1) return a;
  if(b%2==0){
    matrix k = fast(a, b/2);
    return gop(k,k);
  }
  else{
    return gop(fast(a,b-1), a);
  }
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n;
  cin >> n;
  if(n == 1 || n == 2){
    cout << "1\n";
    return 0;
  }
  matrix m(2);
  m[0].pb(1);
  m[0].pb(1);
  m[1].pb(1);
  m[1].pb(0);

  m = fast(m, n-2);
  cout << (m[0][0] + m[0][1])%mod << "\n";
}