#include <iostream>
using namespace std;

int N,tree[1000001]={};
long long M;
int isAble(int h){
  long long sum = 0;
  for(int i=0; i<N; i++){
    if((tree[i] - h) > 0) sum += (tree[i]-h);
  }
  if(sum >= M) return 1;
  else return 0;
}
int bs(int low, int high){
  if(high - low <= 1) return low;
  int mid = (high+low)/2;
  if(isAble(mid)) return bs(mid,high);
  else return bs(low,mid);
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  for(int i=0; i<N; i++) cin >> tree[i];
  cout << bs(0,1000000001);
}