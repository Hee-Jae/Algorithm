#include <iostream>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int arr[100002]={}, sum[100002]={0};
  int N,M, l,r;
  cin >> N >> M;
  for(int i=1; i<=N; i++) cin >> arr[i];
  sum[1] = arr[1];
  for(int i=2; i<=N; i++) sum[i] = sum[i-1] + arr[i];
  for(int i=0; i<M; i++){
    cin >> l >> r;
    cout << sum[r] - sum[l-1] << "\n";
  }
}