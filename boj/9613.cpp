#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define lli long long int
using namespace std;

int gcd(int x, int y){
  int m;
  if(x == 0 || y == 0) return 0;
  while(y!=0){
    m = x%y;
    x = y;
    y = m;
  }
  return x;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t, n, arr[110]={};
  lli sum=0;
  for(cin >> t; t; t--){
    cin >> n;
    sum = 0;
    for(int i=0; i<n; i++) cin >> arr[i];
    for(int i=0; i<n-1; i++){
      for(int j=i+1; j<n; j++){
        sum += gcd(arr[i], arr[j]);
      }
    }
    cout << sum << "\n";
  }

}
