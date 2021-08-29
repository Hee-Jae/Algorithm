#include <iostream>
#include <vector>
#include <string>

using namespace std;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<string> v;
  v.push_back("baby");
  v.push_back("sukhwan");
  v.push_back("tururu");
  v.push_back("turu");
  v.push_back("very");
  v.push_back("cute");
  v.push_back("tururu");
  v.push_back("turu");
  v.push_back("in");
  v.push_back("bed");
  v.push_back("tururu");
  v.push_back("turu");
  v.push_back("baby");
  v.push_back("sukhwan");

  int N, pos, count;
  cin >> N;
  count = N/14;
  pos = N%14-1;
  if(pos == -1) pos = 13;
  if(pos == 2 || pos == 6 || pos == 10){
    if(count >= 3) cout << "tu+ru*" << count+2;
    else{
      cout << v[pos];
      for(int i=0; i<count; i++) cout<<"ru";
    }
  }
  else if(pos == 3 || pos == 7 || pos == 11){
    if(count >= 4) cout << "tu+ru*" << count+1;
    else{
      cout << v[pos];
      for(int i=0; i<count; i++) cout<<"ru";
    }
  }
  else cout << v[pos];
}