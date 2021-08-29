#include <iostream>
#include <algorithm>
#include <vector>
#define pb push_back

using namespace std;

int N,M;
int arr[10]={};
void btk(vector<int> seq, int index){
  seq.pb(arr[index]);
  int size = seq.size();
  if(size == M){
    for(int i=0; i<size; i++) cout << seq[i] << " ";
    cout << "\n";
    return;
  }
  vector<int> tmp;
  int tmpsize=0;
  for(int i=index; i<N; i++){
    if(tmpsize == 0){
      tmp.pb(i);
      tmpsize++;
    }
    else{
      if(arr[i] != arr[tmp[tmpsize-1]]){
        tmp.pb(i);
        tmpsize++;
      }
    }
  }
  for(int i=0; i<tmpsize; i++) btk(seq, tmp[i]);
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  vector<int> seq;
  cin >> N >> M;
  for(int i=0; i<N; i++) cin >> arr[i];
  sort(arr,arr+N);
  for(int i=0; i<N; i++){
    if(i == 0) btk(seq, i);
    else if(arr[i] != arr[i-1] && i != 0) btk(seq, i);
  }
}