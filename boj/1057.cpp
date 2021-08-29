#include <iostream>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N, jimin, hansu, count=0;
  cin >> N >> jimin >> hansu;

  while(1){
    count ++;
    if(jimin%2==0 && hansu == jimin-1) break;
    if(hansu%2==0 && jimin == hansu-1) break;
    if(jimin != 1){
      if(jimin%2 == 0) jimin /=2;
      else jimin = jimin/2 + 1;
    }
    if(hansu != 1){
      if(hansu%2 == 0) hansu /= 2;
      else hansu = hansu/2 + 1;
    }
  }
  cout << count;
}