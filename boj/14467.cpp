#include <iostream>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N, cow[11]={}, c,p, count=0;
  for(int i=1; i<=10; i++) cow[i] = 2;
  cin >> N;
  for(int i=0; i<N; i++){
    cin >> c >> p;
    if(cow[c] == 2) cow[c] = p;
    else{
      if(cow[c] != p){
        count ++;
        cow[c] = p;
      }
    }
  }
  cout << count;
}