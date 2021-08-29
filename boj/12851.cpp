#include <iostream>
#include <queue>
using namespace std;
queue<pair<int, int> > q;
int arr[100002]={};
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N,K, key, count, key_count=0;
  cin >> N >> K;
  arr[N] = 1;
  q.push(make_pair(N,0));
  while(1){
    // cout << q.front().first << " | " << q.front().second << "\n";
    key = q.front().first;
    count = q.front().second;
    arr[key] = 1;
    if(key == K){
      // cout << q.front().first << " | " << q.front().second << "\n";
      while(!q.empty()){
        if(q.front().second == count && q.front().first == key) key_count++;
        q.pop();
      }
      break;
    }
    q.pop();
    if(key-1<=100000 && key-1 >= 0){
      if(arr[key-1] == 0){
        q.push(make_pair(key-1, count+1));
      }
    }
    if(key+1<=100000){
      if(arr[key+1] == 0){
        q.push(make_pair(key+1, count+1));
      }
    }
    if(key*2<=100000){
      if(arr[key*2] == 0){
        q.push(make_pair(key*2, count+1));
      }
    }
  }
  // while(!q.empty()){
  //   // cout << q.front().first << " | " << q.front().second << "\n";
  //   if(q.front().second == count && q.front().first == key) key_count ++;
  //   q.pop();
  // }
  // if(N <= 1 && K > 2) key_count *= 2;
  cout << count << "\n" << key_count;
}