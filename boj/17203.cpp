#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define lli long long int
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N,Q, music[1002]={}, gap[1002]={}, sum[1002]={}, r1,r2;
  cin >> N >> Q;
  for(int i=1; i<=N; i++) cin >> music[i];
  for(int i=1; i<=N-1; i++) gap[i] = abs(music[i+1]-music[i]);
  sum[1] = gap[1];
  for(int i=2; i<=N-1; i++) sum[i] = sum[i-1]+gap[i];
  // for(int i=1; i<=N-1; i++) cout << "sum : " << sum[i] << " ";
  
  for(int i=0; i<Q; i++){
    cin >> r1 >> r2;
    if(r1==r2) cout << 0 << "\n";
    else if(r1<r2) cout << sum[r2-1]-sum[r1-1] << "\n";
    else cout << sum[r1-1]-sum[r2-1] << "\n";
  }
}