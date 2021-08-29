#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
using namespace std;

int N, M;
int arr[10]={};
void btk(vector<int> v, int index){
  v.pb(arr[index]);
  int size = v.size();
  if(size == M){
    for(int i=0 ; i<size; i++){
      cout << v[i] << " ";
    }
    cout << "\n";
    return;
  }
  for(int i=index; i<N; i++) btk(v,i);
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  vector<int> v;
  cin >> N >> M;
  for(int i=0; i<N; i++) cin >> arr[i];
  sort(arr, arr+N);
  for(int i=0; i<N; i++){
    btk(v,i);
  }
}