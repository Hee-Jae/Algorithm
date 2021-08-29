#include <iostream>
#include <algorithm>
using namespace std;
int arr[318]={}, dp[100001]={};
int N;

int maxdp(int num){
  int value=0, min=100000;
  for(int i=316; i>=1; i--){
    value = 0;
    value += num/arr[i];  
    if(num/arr[i] > 0){
      value += dp[num%arr[i]];
    }
    if(min > value && value > 0) min = value;
  }
  return min;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for(int i=1; i<=316; i++) arr[i] = i*i;
  for(int i=1; i<=316; i++) dp[arr[i]] = 1;
  for(int i=1; i<=100000; i++){
    if(dp[i]==0) dp[i] = maxdp(i);
  }
  cout << dp[N];
}