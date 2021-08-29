#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<string> v;
vector<string> ans;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N,M;
  string name;
  cin >> N >> M;
  for(int i=0; i<N; i++){
    cin >> name;
    v.push_back(name);
  }
  for(int j=0; j<M; j++){
    cin >> name;
    v.push_back(name);
  }
  sort(v.begin(), v.end());
  for(int i=0; i<N+M-1; i++){
    if(v[i].compare(v[i+1]) == 0) ans.push_back(v[i]);
  }
  int size = ans.size();
  cout << size << "\n";
  for(int i=0; i<size; i++){
    cout << ans[i] << "\n";
  }
}