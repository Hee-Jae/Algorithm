#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define lli long long int
using namespace std;

int prime[1000002]={1,1}, n, pr[100000]={}, idx=0;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  for(int i=2; i<=1000; i++){
    if(prime[i]==1) continue;
    for(int j=i+i; j<=1000000; j+=i){
      prime[j]=1;
    }
  }
  for(int i=3; i<=1000000; i++)
    if(prime[i]==0) pr[idx++] = i;
  
  int start, end, ck;
  while(1){
    cin >> n;
    if(n==0) break;
    start = 0;
    // end = idx-1;
    // ck = 0;
    while(1){
      if(prime[n-pr[start]] == 0){
        cout << n << " = " << pr[start] << " + " << n-pr[start] << "\n";
        break;
      }
      start++;
    }
    // while(start<=end){
    //   if(pr[start]+pr[end] == n){
    //     cout << n << " = " << pr[start] << " + " << pr[end] << "\n";
    //     ck = 1;
    //     break;
    //   }
    //   else if(pr[start]+pr[end] < n) start++;
    //   else end--;
    // }
    // if(ck==0) cout << "Goldbach\'s conjecture is wrong.\n";
  }
  // int cnt = 0;
  // for(int i=2; i<=100000; i++) if(prime[i]==0) cnt ++;
  // cout << cnt << "\n";
}
