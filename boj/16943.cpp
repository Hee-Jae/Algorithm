#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define lli long long int
using namespace std;

int arr[11]={};

int arrtoint(int n){
  int s=0;
  for(int i=0; i<n; i++) s = s*10 + arr[i];
  return s;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int A,B,idx=0,tmp,found=0;
  cin >> A >> B;
  while(A){
    arr[idx++] = A%10;
    A/=10;
  }
  sort(arr,arr+idx);
  if(arrtoint(idx) > B){
    cout << "-1\n";
    return 0;
  }
  while(next_permutation(arr,arr+idx)){
    if(arr[0]==0) continue;
    if(arrtoint(idx) > B){
      found = 1;
      break;
    }
    else if(arrtoint(idx) == B){
      cout << arrtoint(idx) << "\n";
      return 0;
    }
  }
  // if(found){
  prev_permutation(arr,arr+idx);
  if(arr[0]==0) cout << "-1\n";
  else cout << arrtoint(idx) << "\n";
  // }
  // else cout << "-1\n";
}