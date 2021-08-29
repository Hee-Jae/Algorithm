#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<string> pocket;
vector<pair<string, int> > pocket2;
int bs(int low, int high, string key){
  int mid = (low+high)/2;
  if(pocket2[mid].first.compare(key) == 0) return mid;
  else if(pocket2[mid].first.compare(key) < 0) return bs(mid+1,high,key);
  else return bs(low,mid-1,key);
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N,M;
  string name, order;
  int num;
  cin >> N >> M;
  for(int i=0; i<N; i++){
    cin >> name;
    pocket.push_back(name);
    pocket2.push_back(make_pair(name,i+1));
  }
  sort(pocket2.begin(), pocket2.end());
  for(int i=0; i<M; i++){
    cin >> order;
    if('0' <= order[0] && order[0] <= '9'){
      num = stoi(order)-1;
      cout << pocket[num] << "\n";
    }
    else{
      cout << pocket2[bs(0,N-1,order)].second << "\n";
    }
  }
}