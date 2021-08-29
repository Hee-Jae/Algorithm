#include <iostream>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int X[1002]={}, T, N, sum=0, num, max=-99999;
  for(cin >> T; T; T--){
    cin >> N;
    sum = 0;
    max = -99999;
    for(int i=1; i<=N; i++){
      cin >> num;
      sum += num;
      X[i] = sum;
    }
    for(int i=1; i<=N; i++){
      for(int j=0; j<i; j++){
        sum = X[i]-X[j];
        if(sum > max) max = sum;
      }
    }
    cout << max << "\n";
  }
}