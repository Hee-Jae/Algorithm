#include <iostream>
#include <queue>
#include <cstdlib>
using namespace std;

queue<pair<int, int> > q;
int number[1000001]={};
int remote[10]={};

int isAble(int n){
  if(n==0){
    if(remote[0] == 0) return 1;
    else return 0;
  }
  while(n>0){
    if(remote[n%10] == 1) return 0;
    n/=10;
  }
  return 1;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N, M, temp, x;
  
  cin >> N >> M;
  for(int i=0; i<M; i++){
    cin >> x;
    remote[x] = 1;
  }
  int min=5000000, minnum=0;
  for(int i=0; i<=1000000;i++){
    if(isAble(i) == 1){
      if(abs(N-i) < min){
        min = abs(N-i);
        minnum = i;
      }
    }
  }
  int m1, m2;
  temp = minnum;
  int cnt=0;
  if(temp == 0) cnt = 1;
  else{
    while(temp > 0){
      temp /= 10;
      cnt ++;
    }
  }
  m1 = min + cnt;
  m2 = abs(N-100);
  if(m1 > m2) cout << m2;
  else cout << m1;
}