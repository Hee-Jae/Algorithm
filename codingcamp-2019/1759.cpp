#include <iostream>
#include <algorithm>
using namespace std;

char substr[16]={};
int check(int len){
  int v=0, s=0;
  for(int i=0; i<len; i++){
    if(substr[i] == 'a' || substr[i] == 'e' || substr[i] == 'i' || substr[i] == 'o' || substr[i] == 'u'){
      v ++;
    }
    else s ++;
  }
  if(v>=1 && s>=2) return 1;
  return 0;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int L, C;
  cin >> L >> C;
  char str[16]={};
  int sub[16]={};
  for(int i=0; i<C; i++) cin >> str[i];
  for(int i=0; i<L; i++) sub[i] = 1;
  sort(str, str+C);
  
  for(int i=0, j=0; i<C; i++){
    if(sub[i]==1) substr[j++] = str[i];
  }
  if(check(L)){
    for(int i=0; i<L; i++) cout << substr[i];
    cout << "\n";
  }
  
  while(prev_permutation(sub,sub+C)){
    // cout << "here!\n";
    for(int i=0, j=0; i<C; i++){
      if(sub[i]==1) substr[j++] = str[i];
    }
    if(check(L)){
      for(int i=0; i<L; i++) cout << substr[i];
      cout << "\n";
    }
    else continue; 
  }
}