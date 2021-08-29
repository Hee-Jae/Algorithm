#include <iostream>
#include <vector>
#define pb push_back
using namespace std;

int N, M;

void btk(vector<int> v, int i){
  v.pb(i);

  int size = v.size();
  if(size == M){
    for(int i=0 ; i<size; i++){
      cout << v[i] << " ";

    }
    cout << "\n";
    return;
  }
  for(int i=1; i<=N; i++) btk(v,i);
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  vector<int> v;
  cin >> N >> M;
  for(int i=1; i<=N; i++) btk(v,i);
}