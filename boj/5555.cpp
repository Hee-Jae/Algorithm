#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define lli long long int
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N, cnt = 0, len, same=1;
  char ringdingdongringdingdong[12]={}, letsfindthespecialstring[12]={};
  cin >> letsfindthespecialstring;
  len = strlen(letsfindthespecialstring);
  cin >> N;
  for(int i=0; i<N; i++){
    cin >> ringdingdongringdingdong;
    for(int i=0; i<10; i++){
      same = 1;
      for(int j=0; j<len; j++){
        if(ringdingdongringdingdong[(i+j)%10] != letsfindthespecialstring[j]){
          same = 0;
          break;
        }
      }
      if(same){
        cnt++;
        break;
      }
    }
  }
  cout << cnt;
} // main
