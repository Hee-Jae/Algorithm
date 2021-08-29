#include <iostream>
#include <vector>
#define pb push_back
using namespace std;
int N, M;
void btk(int n, vector<int> v){
  v.pb(n);
  int size = v.size();
  if(size >= 2 && v[size-2] > v[size-1]) return;
  if(size == M){
    for(int i=0; i<size; i++) cout << v[i] << " ";
    cout << "\n";
  }
  else for(int i=1; i<=N; i++) btk(i,v);
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  vector<int> v;
  cin >> N >> M;
  for(int i=1; i<=N; i++) btk(i,v);
}