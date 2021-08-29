#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int size;
  string text;
  cin >> size >> text;
  vector<int> table(size,0);

  int j = 0;
  for(int i=1; i<size; i++){
    while(j>0 && text[i] != text[j]) j = table[j-1];
    if(text[i] == text[j]){
      j ++;
      table[i] = j;
    }
  }
  
  cout << size-table[size-1] << "\n";
}