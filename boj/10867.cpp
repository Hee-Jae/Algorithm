#include <iostream>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int sort[2002]={};
  int N, x;
  cin >> N;
  for(int i=0; i<N; i++){
    cin >> x;
    if(x < 0){
      x *= -1;
      sort[x+1000] = 1;
    }
    else sort[x] = 1;
  }
  for(int i=2000; i>=1001; i--){
    if(sort[i] == 1) cout << (i-1000)*-1 << " ";
  }
  for(int i=0; i<=1000; i++){
    if(sort[i] == 1) cout << i << " ";
  }
}