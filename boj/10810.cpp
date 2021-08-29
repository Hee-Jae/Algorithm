#include <iostream>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int bucket[102]={};
  int N, M, i,j,k;
  cin >> N;;
  for(cin >> M; M; M--){
    cin >> i >> j >> k;
    while(i <= j){
      bucket[i] = k;
      i++;
    }
  }
  for(int i=1; i<=N; i++) cout << bucket[i] << " ";
}