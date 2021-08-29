#include <iostream>
#include <queue>
using namespace std;
priority_queue<double> bigcake;
// priority_queue<double, vector<double>, greater<double> > smallcake;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N,M;
  double c, min=1000000001, smallcake=1000000001;
  cin >> N;
  for(int i=0; i<N; i++){
    cin >> c;
    bigcake.push(c);
    if(c < smallcake) smallcake = c;
  }
  cin >> M;
  double big;
  min = bigcake.top() - smallcake;
  while(M && min != 0){
    big = bigcake.top();
    bigcake.pop();
    bigcake.push(big/2);
    bigcake.push(big/2);
    if(big/2 < smallcake) smallcake = big/2;
    big = bigcake.top();
    cout << big << " | " << smallcake << "(" << big-smallcake << ")\n";
    if(big - smallcake < min) min = big - smallcake;
    M --;
  }
  cout << min;
}