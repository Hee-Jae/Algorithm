#include <iostream>
using namespace std;

int main(){
  int N, s, cnt=0;
  cin >> N;
  for(int i=1; i<=N; i++){
    cin >> s;
    if(s!=i) cnt ++;
  }
  cout << cnt;
}