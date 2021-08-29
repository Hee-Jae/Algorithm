#include <iostream>
using namespace std;

int area[10001]={}, N;

int getmax(int value){
  int sum=0;
  for(int i=0; i<N; i++){
    if(area[i] < value) sum += area[i];
    else sum += value;
  }
  return sum;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int limit, mid, min=0, max=999999, ans;
  cin >> N;
  for(int i=0; i<N; i++) cin >> area[i];
  cin >> limit;

  while(min+1 < max){
    mid = (min+max)/2;
    if(getmax(mid) <= limit) min = mid;
    else max = mid;
  }
  
  for(int i=0; i<N; i++) if(area[i] > min) area[i] = min;
  ans = area[0];
  for(int i=0; i<N; i++)
    if(area[i] > ans) ans = area[i];

  cout << ans << "\n";
}