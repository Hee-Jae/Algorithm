#include <iostream>
#include <vector>
#define pb push_back
using namespace std;
int N, M;
int visit[10]={};
void btk(int n, vector<int> v){
  visit[n] = 1;
  v.pb(n);
  int size = v.size();
  if(size == M){
    for(int i=0; i<size; i++){
      cout << v[i] << " ";
    }
    cout << "\n";
    visit[n] = 0;
  }
  else{
    for(int i=1; i<=N; i++){
      if(!visit[i]){
        btk(i,v);
      }
    }
  }
  visit[n] = 0;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  vector<int> v;
  cin >> N >> M;
  for(int i=1; i<=N; i++) btk(i,v);
}