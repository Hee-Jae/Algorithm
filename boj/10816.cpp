#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int card[500001]={};
int key[500001]={};
vector<pair<int, int> > v;
int bs(int low, int high, int key){
  if(low > high) return -1;
  int mid = (low+high)/2;
  if(v[mid].first == key) return mid;
  else if(v[mid].first < key) return bs(mid+1, high, key);
  else return bs(low, mid-1, key);
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N,M, pos, temp, cnt=1, size;
  cin >> N;
  for(int i=0; i<N; i++) cin >> card[i];
  sort(card, card+N);
  temp = card[0];
  for(int i=1; i<N; i++){
    if(card[i] == temp) cnt++;
    else{
      v.push_back(make_pair(temp,cnt));
      cnt = 1;
      temp = card[i];
    }
  }
  v.push_back(make_pair(temp,cnt));
  size = v.size();
  
  cin >> M;
  for(int i=0; i<M; i++) cin >> key[i];
  for(int i=0; i<M; i++){
    pos = bs(0,size-1,key[i]);
    if(pos ==  -1) cout << 0 << " ";
    else cout << v[pos].second << " ";
  }
  // for(int i=0; i<size; i++){
  //   cout << v[i].first << " | " << v[i].second << "\n";
  // }  
} // main