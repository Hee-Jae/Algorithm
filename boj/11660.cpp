#include <iostream>
using namespace std;

int arr[1026][1026]={};
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N, M, x1,x2,y1,y2;
  cin >> N >> M;
  for(int i=1; i<=N; i++)
    for(int j=1; j<=N; j++) cin >> arr[i][j];

  for(int i=2; i<=N; i++){
    arr[1][i] += arr[1][i-1];
    arr[i][1] += arr[i-1][1];
  }
  for(int i=2; i<=N; i++){
    for(int j=2; j<=N; j++){
      arr[i][j] += (arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1]);
    }
  }
  int sum=0;
  for(int i=0; i<M; i++){
    cin >> x1 >> y1 >> x2 >> y2;
    sum += arr[x2][y2];
    sum -= arr[x1-1][y2];
    sum -= arr[x2][y1-1];
    sum += arr[x1-1][y1-1];
    cout << sum << "\n";
    sum = 0;
  }
}