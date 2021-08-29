#include <iostream>
#include <stack>
using namespace std;
int arr[1000001]={};
int temp[1000001]={};
int cnt[1000001]={};
stack<int> s;
int size = 1;
int bs(int x, int low, int high){
  if(low > high) return low;
  int mid = (low+high)/2;
  if(temp[mid] > x) return bs(x,low,mid-1);
  else if(temp[mid] < x) return bs(x,mid+1, high);
  else return mid;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N, index;
  cin >> N;
  for(int i=0; i<N; i++) cin >> arr[i];
  temp[0] = arr[0];
  cnt[0] = 1;
  for(int i=1; i<N; i++){
    if(arr[i] > temp[size-1]){
      temp[size] = arr[i];
      size ++;
      cnt[i] = size;
    }
    else if(arr[i] < temp[size-1]){
      index = bs(arr[i],0,size-1);
      temp[index] = arr[i];
      cnt[i] = index+1;
    }
  }
  // cout << "test\n";
  // for(int i=0; i<N; i++) cout << cnt[i] << " ";
  // cout << "\n";
  cout << size << '\n';
  for(int i=N-1; i>=0; i--){
    if(cnt[i] == size){
      s.push(arr[i]);
      size --;
    }
  }
  while(!s.empty()){
    cout << s.top() << " ";
    s.pop();
  }
}