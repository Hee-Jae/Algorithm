#include <iostream>
#include <map>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T, K, num, key;
  char order;
  map<int, int> m;
  map<int, int> cnt;
  map<int, int> ::iterator it;
  for(cin>>T; T; T--){
    m.clear();
    cnt.clear();
    for(cin>>K; K; K--){
      cin >> order;
      if(order == 'I'){
        cin >> num;
        m.insert(make_pair(num, num));
        cnt[num]++;
      }
      else{
        cin >> num;
        if(m.empty()) continue;
        if(num == -1){
          key = m.begin()->first;
          if(cnt[key] > 1) cnt[key]--;
          else{
            m.erase(key);
            cnt[key]--;
          }
        }
        else{
          it = m.end();
          it--;
          key = it->first;
          if(cnt[key] > 1) cnt[key]--;
          else{
            m.erase(key);
            cnt[key]--;
          }
        }
      } //  order == D
    } // K
    if(m.empty()) cout << "EMPTY\n";
    else{
      it = m.end();
      it--;
      cout << it->second << " " << m.begin()->second << "\n";
    }
  } // Test Case
} // main