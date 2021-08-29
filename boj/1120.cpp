#include <iostream>
#include <string>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  string A,B;
  cin >> A >> B;
  int min=54321, cnt=0;
  int Asize = A.size(), Bsize = B.size();
  for(int i=0; i<=Bsize-Asize; i++){
    cnt = 0;
    for(int j=0; j<Asize; j++){
      if(A[j] != B[i+j]) cnt++; 
    }
    if(cnt < min) min = cnt;
  }
  cout << min;
}