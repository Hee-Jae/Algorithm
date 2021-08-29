#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define lli long long int
using namespace std;
lli N,K, lan[10002]={};
lli getN(lli n){
  lli s=0;
  for(int i=0; i<K; i++) s += (lan[i]/n);
  return s;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> K >> N;
  for(int i=0; i<K; i++) cin >> lan[i];
  lli low = 0, high = 99999999999, mid;
  while(low+1<high){
    mid = (low+high)/2;
    if(getN(mid) < N) high = mid;
    else low = mid;
    // cout << "mid : " << mid << " ("<<low << "," << high << ")\n";
  }
  if(getN(high) >= N) cout << high;
  else cout << low;
}
