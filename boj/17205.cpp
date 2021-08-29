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
int N;
char pswd[11]={};
lli sum=0;

lli power(int a, int b){
  lli res = 1;
  while(b){
    res *= a;
    b--;
  }
  return res;
}
lli gettime(int k){
  lli sum = 0;
  for(int i=0; i<=N-k-1; i++){
    sum += power(26,i);
  }
  sum *= (pswd[k]-'a');
  return sum;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> pswd;
  int len = strlen(pswd);
  for(int i=0; i<len; i++){
    sum += (gettime(i)+1);
  }
  cout << sum;
}