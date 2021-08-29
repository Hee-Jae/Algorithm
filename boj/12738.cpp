#include <iostream>
using namespace std;
int arr[1000001]={};
int temp[1000001]={};
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
  int N;
  cin >> N;
  for(int i=0; i<N; i++) cin >> arr[i];
  temp[0] = arr[0];
  for(int i=1; i<N; i++){
    if(arr[i] > temp[size-1]){
      temp[size] = arr[i];
      size ++;
    }
    else if(arr[i] < temp[size-1]){
      temp[bs(arr[i],0,size-1)] = arr[i];
    }
  }
  cout << size;
}