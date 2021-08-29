#include <iostream>
using namespace std;

int arr[1010][1010]={};
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N, M, x1,x2,y1,y2, Q;
  cin >> N >> M >> Q;
  for(int i=1; i<=N; i++)
    for(int j=1; j<=M; j++) cin >> arr[i][j];

  for(int i=2; i<=M; i++) arr[1][i] += arr[1][i-1];
  for(int i=2; i<=N; i++) arr[i][1] += arr[i-1][1];
  
  for(int i=2; i<=N; i++){
    for(int j=2; j<=M; j++){
      arr[i][j] += (arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1]);
    }
  }
  int sum=0;
  for(; Q; Q--){
    cin >> x1 >> y1 >> x2 >> y2;
    sum += arr[x2][y2];
    sum -= arr[x1-1][y2];
    sum -= arr[x2][y1-1];
    sum += arr[x1-1][y1-1];
    cout << sum/((x2-x1+1)*(y2-y1+1)) << "\n";
    sum = 0;
  }
}