#include <iostream>
using namespace std;

int N, maxpay=0;
int T[16]={}, P[16]={};

void getmax(int i, int pay){
  if(maxpay < pay) maxpay = pay;
  if(i >= N) return;
  if(i+T[i] <= N) getmax(i+T[i], pay+P[i]);
  if(i+1 < N) getmax(i+1, pay);
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N;
  for(int i=0; i<N; i++) cin >> T[i] >> P[i];
  getmax(0, 0);
  cout << maxpay;
}