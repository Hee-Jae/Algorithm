#include <iostream>
#include <queue>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T, M, n, pr=0, bsize=0, ssize=0;
  for(cin >> T; T; T--){
    cin >> M;
    cout << M/2 +1 << "\n";
    priority_queue<int> b;
    priority_queue<int, vector<int>, greater<int> > s;
    bsize=0;
    ssize=0;
    pr =0;
    for(int i=0; i<M; i++){
      cin >> n;
      if(i==0){
        b.push(n);
        bsize++;
      }
      else{
        if(n < b.top()){
          b.push(n);
          bsize ++;
        }
        else{
          s.push(n);
          ssize++;
        }
      }
      if(ssize > bsize){
        b.push(s.top());
        bsize++;
        s.pop();
        ssize--;
      }
      if(bsize-ssize == 2){
        s.push(b.top());
        ssize++;
        b.pop();
        bsize--;
      }
      if(i%2==0){
        cout << b.top() << " ";
        pr++;
      }
      if(pr==10){
        cout << "\n";
        pr = 0;
      }
    }
    cout << "\n";
  } 
}