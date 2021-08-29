#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, arr[10001]={};
  cin >> N;
  for(int i=0; i<N; i++) cin >> arr[i];
  if(prev_permutation(arr, arr+N))
    for(int i=0; i<N; i++) cout << arr[i] << " ";
  else cout << "-1";
}