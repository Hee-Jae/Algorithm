#include <iostream>
using namespace std;

int A[1000000]={};
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N, B,C;
  long long count=0;
  cin >> N;
  for(int i=0; i<N; i++) cin >> A[i];
  cin >> B >> C;
  for(int i=0; i<N; i++){
    A[i] -= B;
    count ++;
    if(A[i] > 0){
      count += A[i]/C;
      if(A[i]%C != 0) count++;
    }
  }
  cout << count;
}