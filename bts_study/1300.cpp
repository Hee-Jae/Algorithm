#include <iostream>
#define ll long long
using namespace std;

int mini(int a, int b){
  if(a>b) return b;
  else return a;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N,k;
  cin >> N >> k;
  
  int low = 1, high = k, mid;
  int cnt = 0;
  while(low <= high){
    cnt = 0;
    mid = (low+high)/2;
    for(int i=1; i<=N; i++){
      cnt += mini(mid/i, N);
    }
    if(cnt < k) low = mid+1;
    else high = mid-1;
  }
  cout << low;
}

