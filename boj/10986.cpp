#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define lli long long int
using namespace std;
int N,M;
lli arr[1000002]={}, mod[1001]={};
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  cin >> arr[0];
  for(int i=1; i<N; i++){
    cin >> arr[i];
    arr[i] += arr[i-1];
  }
  for(int i=0; i<N; i++) mod[arr[i]%M]++;

  lli sum=0;
  for(int i=0; i<=1000; i++){
    if(mod[i] > 0) 
      sum += (mod[i]*(mod[i]-1))/2;
  }
  sum += mod[0];
  cout << sum;
}
