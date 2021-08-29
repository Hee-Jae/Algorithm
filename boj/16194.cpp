#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define lli long long int
#define INF 987654321
using namespace std;

int arr[1001]={}, dp[1001]={};

int mindp(int n){
  int value=0, min=INF;
  for(int i=n-1; i>=1; i--){
    value = 0;
    value += dp[i] * (n/i);
    value += dp[n%i];
    if(min > value) min = value;
  }
  return min;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin >> N;
  for(int i=1; i<=N; i++) cin >> arr[i];
  dp[1] = arr[1];
  for(int i=2; i<=N; i++) dp[i] = min(mindp(i),arr[i]);
  cout << dp[N];
}
