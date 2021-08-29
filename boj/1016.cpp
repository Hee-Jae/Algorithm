#include <iostream>
using namespace std;

long long jegop[1000002]={};
long long num[1000002]={};
long long check[1000002]={};
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  for(long long i=2; i<=1000000; i++) jegop[i] = i*i;
  long long min, max;
  cin >> min >> max;
  num[1] = min;
  long long len = max-min+1;
  for(int i=2; i<=len; i++) num[i] = num[i-1] + 1;
  for(int i=2; i<=1000000; i++){
    long long j = 1;
    if(num[j]%jegop[i] != 0) j += jegop[i]-(num[j]%jegop[i]);
    for(; j<=len; j+=jegop[i]){
      // cout << num[j] << " ";
      check[j] = 1;
    }
  }
  // cout << "\n";
  
  long long count=0;
  for(long long i=1; i<=len; i++){
    if(check[i]==1) count ++;
    // cout << num[i] << "\n";
  }
  cout << len-count;
}