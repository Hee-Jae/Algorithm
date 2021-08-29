#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main(){
  map<long, int> m;
  map<long, int> ::iterator it;
  m.insert(make_pair(137438953472,30));
  m.insert(make_pair(1,10));
  m.insert(make_pair(3,20));
  // m[4]=50;
  cout << m[137438953472] << "\n";
  cout << m[4] << "\n";
  // cout << m[5] << "\n";
  // cout << m[2] << "\n";
  // if(m[10]==1) cout << "-\n";
  // // m.erase(137438953472);
  // cout << m.size() << "\n";
  // long long zero = 0;
  // // cout << (zero<<37) << "\n";
  // m[(zero|(2<<4)) | (zero|(1<<0))] = 77;
  // cout << ((zero|(2<<4)) | (zero|(1<<0))) << "\n";
  // cout << m[33] << "\n";
  // for(it=m.begin(); it!=m.end(); it++) cout << it-> first << " : " <<it->second << "\n";
  // cout << m.begin()->first << " : " <<m.begin()->second << "\n";
  // it = m.end();
  // it --;
  // cout << m.end()->first << " : " << m.end()->second << "\n";
  // cout << map[0] << "\n";
}