#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  vector<string> v;
  int len;
  string str;
  cin >> str;
  len = str.length();
  for(int i=0; i<len; i++){
    v.push_back(str.substr(i));
  }
  sort(v.begin(), v.end());
  for(int i=0; i<len; i++){
    cout << v[i] << "\n";
  }
}