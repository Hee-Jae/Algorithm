#include <iostream>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N,M,K[1001]={};
  int num[1001]={};
  cin >> N >> M;
  for(int i=0; i<M; i++) cin >> K[i];
  for(int i=0; i<M; i++){
    for(int j=K[i]; j<=N; j+=K[i]){
      if(num[j] == 0) num[j] = 1;
    }
  }
  int sum=0;
  for(int i=2; i<=N; i++){
    if(num[i]) sum += i;
  }
  cout << sum;
}