#include <iostream>
using namespace std;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N,M;
  cin >> N >> M;
  for(int i=0; i<N; i++){
    for(int j=1; j<=M; j++){
      if(j == M) cout << (M*i)+j << '\n';
      else cout << (M*i)+j << " ";
    }
  }
}