#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define lli long long int
using namespace std;
int N, A[15]={}, MaxValue=-1e9, MinValue=1e9;

void simulation(int value, vector<int> v, int op, int idx){
  if(idx == N){
    if(MaxValue < value) MaxValue = value;
    if(MinValue > value) MinValue = value;
    return;
  }
  v[op]--;
  for(int i=0; i<4; i++){
    if(v[i] == 0) continue;
    if(i==0) simulation(value+A[idx], v, 0, idx+1);
    else if(i==1) simulation(value-A[idx], v, 1, idx+1);
    else if(i==2) simulation(value*A[idx], v, 2, idx+1);
    else if(i==3) simulation(value/A[idx], v, 3, idx+1);
  }
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for(int i=0; i<N; i++) cin >> A[i];
  vector<int> v(5);
  for(int i=0; i<4; i++) cin >> v[i];

  simulation(A[0], v,4,1);
  cout << MaxValue << "\n" << MinValue << "\n";
}
