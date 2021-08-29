#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int arr[1001]={};
  int N;
  cin >> N;
  for(int i=0; i<N; i++) cin >> arr[i];
  sort(arr, arr+N);
  int weight=1;
  for(int i=0; i<N; i++){
    if(weight < arr[i]) break;
    weight += arr[i];
  }
  cout << weight;
}