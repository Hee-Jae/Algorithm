#include <iostream>
#include <algorithm>
using namespace std;

long long gm[3000]={};
int idx = 0;
void makegm(long long n){
  if(n > 1000000000) return;
  gm[idx++] = n;
  makegm(n*10 + 4);
  makegm(n*10 + 7);
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int A,B, count=0;
  cin >> A >> B;
  makegm(4);
  makegm(7);
  sort(gm, gm+idx);
  for(int i=0; i<idx; i++){
    if(gm[i] >= A  && gm[i] <= B) count ++;
  }
  cout << count;
}