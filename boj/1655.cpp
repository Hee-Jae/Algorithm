#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define lli long long int
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N,x,mid, smallsize=0, bigsize=0;
  priority_queue<int> small;
  priority_queue<int> big;
  cin >> N;
  cin >> x;
  mid = x;
  cout << x << "\n";

  for(--N; N; N--){
    cin >> x;
    if(x <= mid){
      if(smallsize >= bigsize){
        big.push(-mid);
        bigsize++;
        small.push(x);
        mid = small.top();
        small.pop();
      }
      else{
        small.push(x);
        smallsize++;
      }
    }
    else{
      if(smallsize >= bigsize){
        big.push(-x);
        bigsize++;
      }
      else{
        small.push(mid);
        smallsize++;
        big.push(-x);
        mid = -big.top();
        big.pop();
      }
    }
    cout << mid << "\n";
    // cout << "[" << mid << "]" << "\n";
  }
}