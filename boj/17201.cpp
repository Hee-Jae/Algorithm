#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define lli long long int
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  char mag[20]={};
  int n, flag=0;
  cin >> n;
  cin >> mag;

  for(int i=1; i<n; i++){
    if(mag[i*2] != mag[0]) flag = 1;
    if(mag[i*2+1] != mag[1]) flag = 1;
  }
  if(flag) cout << "No";
  else cout << "Yes";
}