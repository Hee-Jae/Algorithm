#include <iostream>
#include <stdio.h>

using namespace std;
int main(){
  size_t s = 0;
  int m = -1;

  if(s < m){
    cout << "minus win!\n";
  } else{
    cout << "unsigned win!\n";
  }

  printf("%x %x\n", s, m);
}