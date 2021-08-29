#include <iostream>
using namespace std;

int N, area[10001]={};

int getsum(int mid){
  int sum = 0;
  for(int i=0; i<N; i++){
    if(area[i] < mid) sum += area[i];
    else sum += mid;
  }
  return sum;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int limit;
  cin >> N;
  for(int i=0; i<N; i++) cin >> area[i];
  cin >> limit;

  int low = 0, high = 200000, mid;

  while(low+1 < high){
    mid = (low+high)/2;
    if(getsum(mid) <= limit) low = mid;
    else high = mid;
  }

  for(int i=0; i<N; i++){
    if(area[i] > low) area[i] = low;
  }

  /* 여기 까지 했으면 area 배열에서 가장 큰 값 뽑아! 그게 답이야 !*/  
}