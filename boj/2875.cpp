#include <iostream>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N,M,K, team, rf=0, rm=0;
  cin >> N >> M >> K;
  if(N >= M*2) team = M;
  else team = N/2;
  rf = N - team*2;
  rm = M - team;
  K -= (rf + rm);
  while(K>0){
    K -= 3;
    team --;
  }
  cout << team;
}