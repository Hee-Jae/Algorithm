#include <iostream>
using namespace std;

int arr[100001]={}, sum[100001]={};
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N,M, a,b;
  cin >> N;
  for(int i=1; i<=N; i++) cin >> arr[i];
  sum[1] = arr[1];
  for(int i=1; i<=N; i++) sum[i] = sum[i-1] + arr[i];
  cin >> M;
  for(int i=1; i<=M; i++){
    cin >> a >> b;
    cout << sum[b] - sum[a-1] << "\n";
  }
}