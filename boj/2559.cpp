#include <iostream>

using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N, K;
  int arr[100001]={}, sum[100000]={};
  cin >> N >> K;
  for(int i=0; i<N; i++) cin >> arr[i];

  int temp=0, start=0, end=K, index=1;
  for(int i=0; i<K; i++) temp += arr[i];
  sum[0] = temp;
  while(end < N){
    temp -= arr[start++];
    temp += arr[end++];
    sum[index++] = temp;
  }

  int max = sum[0];
  for(int i=1; i<index; i++) if(sum[i] > max) max = sum[i];

  // for(int i=0; i<index; i++) cout << sum[i] << "\n";
  cout << max;
}