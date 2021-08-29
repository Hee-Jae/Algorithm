#include <iostream>
#include <vector>
#include <cmath>
#define pb push_back
using namespace std;
int N, mini=1e9, sum=0;
int S[21][21]={}, visit[21]={};

int sumA(vector<int> v){
  int sum = 0, team[11]={};
  int idx=0, size=v.size();
  for(int i=0; i<size; i++) visit[v[i]] = 1;
  for(int i=0; i<N; i++){
    if(!visit[i]) team[idx++] = i;
  }
  for(int i=0; i<idx; i++){
    for(int j=0; j<idx; j++){
      sum += S[team[i]][team[j]];
    }
  }
  for(int i=0; i<size; i++) visit[v[i]] = 0;
  return sum;
}
int sumB(vector<int> v){
  int sum = 0, team[11]={};
  int idx=0, size=v.size();
  for(int i=0; i<size; i++) visit[v[i]] = 1;
  for(int i=0; i<N; i++){
    if(visit[i]) team[idx++] = i;
  }
  for(int i=0; i<idx; i++){
    for(int j=0; j<idx; j++){
      sum += S[team[i]][team[j]];
    }
  }
  for(int i=0; i<size; i++) visit[v[i]] = 0;
  return sum;
}
void getmini(vector<int> v, int n){
  v.pb(n);
  int size = v.size();
  if(size == N/2){
    int a=sumA(v), b=sumB(v);
    if(abs(a-b) < mini) mini = abs(a-b);
    return;
  }
  for(int i=n+1; i<N; i++) getmini(v, i);
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  vector<int> v;
  cin >> N;
  for(int i=0; i<N; i++)
    for(int j=0; j<N; j++) cin >> S[i][j];

  getmini(v,0);
  cout << mini;
}