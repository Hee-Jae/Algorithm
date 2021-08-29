#include <iostream>
using namespace std;

int irgb(int r, int g, int b){
  return r*2126 + g*7152 + b*722;
}
int asc(int n){
  if(0 <= n && n < 510000) return 35;
  else if(510000 <= n && n < 1020000) return 111;
  else if(1020000 <= n && n < 1530000) return 43;
  else if(1530000 <= n && n < 2040000) return 45;
  else return 46;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N,M, r,g,b;
  cin >> N >> M;
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      cin >> r >> g >> b;
      cout << (char)(asc(irgb(r,g,b)));
    }
    cout << "\n";
  }
}