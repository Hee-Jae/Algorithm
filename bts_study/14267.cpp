#include <iostream>
#include <vector>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  vector<pair<int, int> > v;
  int n,m,b, id,w;
  cin >> n >> m;
  for(int i=0; i<n; i++){
    cin >> b;
    v.push_back(make_pair(b,0));
  }
  for(int i=0; i<m; i++){
    cin >> id >> w;
    v[id-1].second += w;
  }
  
  int sangsa;
  for(int i=1; i<n; i++){
    sangsa = v[i].first-1;
    v[i].second += v[sangsa].second;
  }
  for(int i=0; i<n; i++) cout << v[i].second << " ";
}