#include <iostream>
#include <queue>
using namespace std;
queue<pair<int, int> > q;
int arr[100002]={};
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N,K, key, count;
  cin >> N >> K;
  arr[N] = 1;
  q.push(make_pair(N,0));
  while(1){
    key = q.front().first;
    count = q.front().second;
    if(key == K){
      cout << count;
      break;
    }
    q.pop();
    if(key-1<=100000 && key-1 >= 0){
      if(!arr[key-1]){
        q.push(make_pair(key-1, count+1));
        arr[key-1] = 1;
      }
    }
    if(key+1<=100000){
      if(!arr[key+1]){
        q.push(make_pair(key+1, count+1));
        arr[key+1] = 1;
      }
    }
    if(key*2<=100000){
      if(!arr[key*2]){
        q.push(make_pair(key*2, count+1));
        arr[key*2] = 1;
      }
    }
  }
}