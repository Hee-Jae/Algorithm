#include <iostream>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N, M, card[101]={};
  cin >> N >> M;
  for(int i=0; i<N; i++) cin >> card[i];
  
  int sum=0, max=0;
  for(int i=0; i<N-2; i++){
    for(int j=i+1; j<N-1; j++){
      for(int k=j+1; k<N; k++){
        sum = card[i] + card[j] + card[k];
        if(sum <= M && sum > max) max = sum;
      }
    }
  }
  cout << max;
}