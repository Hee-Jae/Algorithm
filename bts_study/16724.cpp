#include <iostream>
using namespace std;

char jido[1001][1001]={};
int root[1000001]={};
int rootlist[1000001]={};

int find(int n){
  if(root[n] == n) return n;
  return root[n] = find(root[n]);
}
void merge(int a, int b){
  root[find(a)] = find(b);
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N,M, r, rootidx=0;
  cin >> N >> M;
  for(int i=0; i<N; i++) cin >> jido[i];
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      root[rootidx++] = i*M + j;
    }
  }
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      if(jido[i][j] == 'D') r = (i+1)*M+j;
      else if(jido[i][j] == 'U') r = (i-1)*M+j;
      else if(jido[i][j] == 'L') r = i*M+j-1;
      else if(jido[i][j] == 'R') r = i*M+j+1;
      merge(i*M+j, r);
    }
  }
  int cnt = 0;
  for(int i=0; i<rootidx; i++) rootlist[find(root[i])] = 1;
  for(int i=0; i<rootidx; i++){
    if(rootlist[i] == 1) cnt ++;
  }
  cout << cnt << "\n";
}