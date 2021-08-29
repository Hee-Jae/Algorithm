#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N,M;
  string str, pattern;
  cin >> N >> M >> str;
  pattern = "I";
  for(int i=0; i<N; i++) pattern += "OI";

  // cout << pattern << "\n";
  int patternSize = N*2+1, j=0;
  vector<int> pi(patternSize,0);
  for(int i=1; i<patternSize; i++){
    while(j>0 && pattern[i] != pattern[j]) j = pi[j-1];
    if(pattern[i] == pattern[j]){
      j ++;
      pi[i] = j;
    }
  }
  
  j=0;
  int cnt = 0;
  for(int i=0; i<M; i++){
    while(j>0 && str[i] != pattern[j]) j = pi[j-1];
    if(pattern[j] == str[i]){
      if(j == patternSize-1){
        cnt++;
        j = pi[j];
      }
      else j++;
    }
  }
  cout << cnt;
}