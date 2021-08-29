#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define lli long long int
using namespace std;

int N;
int arr[501][501]={};
lli fact[501]={1};
vector<int> v;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++) cin >> arr[i][j];
  }

  for(int i=1; i<=500; i++)
    fact[i] = (fact[i-1] * i)%1000000007;
  
  // for(int i=1; i<=500; i++) cout << "fact : " << fact[i] << "\n";

  lli ans = 1;
  int flag = 0, same=1;
  for(int i=0; i<N-1; i++){
    same = 1;
    if(arr[i][0] == -1) continue;
    for(int j=i+1; j<N; j++){
      flag = 0;
      for(int k=0; k<N; k++){
        if(arr[i][k] != arr[j][k]){
          flag = 1;
          break;
        }
      }
      if(flag==0){
        same++;
        arr[j][0] = -1;
      }
    }
    if(same > 1) v.pb(same);
  }
  // for(int i=0; i<v.size(); i++) cout << v[i] << "\n";
  for(int i=0; i<v.size(); i++){
    ans *= fact[v[i]];
    ans %= 1000000007;
  }
  cout << ans;
}