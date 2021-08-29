#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define lli long long int
using namespace std;

int arr[80000]={}, sum[80000]={}, pos[80001][2]={};

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T,N,index=0, tmp;
  tmp = 3;
  while(tmp <= 80000){
    arr[index++] = tmp;
    tmp += 3;
  }
  tmp = 7;
  while(tmp <= 80000){
    if(tmp%21!=0) arr[index++] = tmp;
    tmp += 7;
  }
  sort(arr,arr+index);
  // cout << "index : " << index << "\n"; 
  sum[0] = arr[0];
  for(int i=1; i<index; i++) sum[i] = sum[i-1] + arr[i];  
  // for(int i=0; i<index; i++){
  //   pos[arr[i]][0] = 1;
  //   pos[arr[i]][1] = i;
  // }

  // for(int i=0; i<=80000; i++) if(pos[i][0] == 1) cout << i << " ";
  for(cin >> T; T; T--){
    cin >> N;
    N = (N/3) + (N/7) - (N/21) -1;
    // while(pos[N][0] == 0) N--;
    cout << sum[N] << "\n";
  }
}