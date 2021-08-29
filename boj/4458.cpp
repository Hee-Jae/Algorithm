
#include <iostream>
#include <string>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N, diff='a'-'A';
  string s;
  cin >> N;
  getline(cin, s);
  for(int i=0; i<N; i++){
    getline(cin, s);
    if(s[0] > 'Z') s[0] -= diff;
    cout << s << "\n";
  }
}