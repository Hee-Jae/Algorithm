#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define lli long long int
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int arr[52]={};
  int a,b,n;
  cin >> n;
  for(int i=0; i<n; i++) cin >> arr[i];
  
  if(n==1){
    cout << "A";
    return 0;
  }
  else if(n==2){
    if(arr[0] != arr[1]) cout << "A";
    else cout << arr[0];
    return 0;
  }
  int notsame = 0;
  for(int i=1; i<n; i++){
    if(arr[i] != arr[i-1]) notsame = 1;
  }
  if(!notsame){
    cout << arr[0];
    return 0;
  }

  if((arr[1]-arr[0]) == 0){
    cout << "B";
    return 0;
  }

  a = (arr[2]-arr[1])/(arr[1]-arr[0]);
  b = arr[1]-(arr[0]*a);
  
  int flag = 0;
  for(int i=0; i<n-1; i++){
    if((arr[i]*a+b) != arr[i+1]) flag = 1;
  }
  if(flag) cout << "B";
  else cout << arr[n-1]*a+b;
}