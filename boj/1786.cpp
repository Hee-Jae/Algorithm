#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  string text, pattern;
  getline(cin,text);
  getline(cin,pattern);
  
  int textSize = text.size(), patternSize = pattern.size();
  vector<int> table(patternSize,0);
  int j = 0;
  for(int i=1; i<patternSize; i++){
    while(j>0 && pattern[i] != pattern[j]) j = table[j-1];
    if(pattern[i] == pattern[j]){
      j ++;
      table[i] = j;
    }
  }
  j=0;
  int cnt = 0;
  vector<int> pos;
  for(int i=0; i<textSize; i++){
    while(j>0 && text[i] != pattern[j]) j = table[j-1];
    if(text[i] == pattern[j]){
      if(j == patternSize-1){
        cnt ++;
        pos.push_back(i-patternSize+2);
        j = table[j];
      }
      else j++;
    }
  }
  cout << cnt << "\n";
  for(int i=0; i<cnt; i++) cout << pos[i] << " ";
}